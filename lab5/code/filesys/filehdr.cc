// filehdr.cc
//	Routines for managing the disk file header (in UNIX, this
//	would be called the i-node).
//
//	The file header is used to locate where on disk the
//	file's data is stored.  We implement this as a fixed size
//	table of pointers -- each entry in the table points to the
//	disk sector containing that portion of the file data
//	(in other words, there are no indirect or doubly indirect
//	blocks). The table size is chosen so that the file header
//	will be just big enough to fit in one disk sector,
//
//      Unlike in a real system, we do not keep track of file permissions,
//	ownership, last modification date, etc., in the file header.
//
//	A file header can be initialized in two ways:
//	   for a new file, by modifying the in-memory data structure
//	     to point to the newly allocated data blocks
//	   for a file already on disk, by reading the file header from disk
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"

#include "filehdr.h"
#include "system.h"

//----------------------------------------------------------------------
// FileHeader::Allocate
// 	Initialize a fresh file header for a newly created file.
//	Allocate data blocks for the file out of the map of free disk blocks.
//	Return FALSE if there are not enough free blocks to accomodate
//	the new file.
//
//	"freeMap" is the bit map of free disk sectors
//	"fileSize" is the bit map of free disk sectors
//----------------------------------------------------------------------

bool FileHeader::Allocate(BitMap *freeMap, int fileSize) {
  createTime = time(NULL);
  lastAccessTime = createTime;
  lastModifyTime = createTime;
  // readerCnt = new int;
  // userCnt = new int;
  // *readerCnt = 0;
  // *userCnt = 0;
  // userSema = new Semaphore("user mutex", 1);
  // mutex = new Semaphore("readerCnt mutex", 1);
  // writeSema = new Semaphore("critical mutex", 1);

  numBytes = fileSize;
  numSectors = divRoundUp(fileSize, SectorSize);
  DEBUG('f', "Allocate NumBytes: %d, NumSectors: %d\n", numBytes, numSectors);
  int trueSectors = numSectors + divRoundUp(numSectors, NumDirect) - 1;
  if (freeMap->NumClear() < trueSectors) {
    return FALSE; // not enough space
  }
  if (numSectors > NumDirect) {
    nextHeaderSector = freeMap->Find();
    DEBUG('f', "Allocate extra header at %d\n", nextHeaderSector);
    FileHeader *nxt = new FileHeader;
    ASSERT(nxt->Allocate(freeMap, fileSize - NumDirect * SectorSize));
    nxt->WriteBack(nextHeaderSector); // Writing back to sector
    delete nxt;
  } else {
    nextHeaderSector = -1;
  }
  for (int i = 0; i < min(NumDirect, numSectors); i++) {
    dataSectors[i] = freeMap->Find();
  }
  return TRUE;
}

//----------------------------------------------------------------------
// FileHeader::Deallocate
// 	De-allocate all the space allocated for data blocks for this file.
//
//	"freeMap" is the bit map of free disk sectors
//----------------------------------------------------------------------

void FileHeader::Deallocate(BitMap *freeMap) {
  if (nextHeaderSector != -1) {
    FileHeader *nxt = new FileHeader;
    nxt->FetchFrom(nextHeaderSector);
    nxt->Deallocate(freeMap);
    delete nxt;
  }
  for (int i = 0; i < min(NumDirect, numSectors); i++) {
    ASSERT(freeMap->Test((int)dataSectors[i])); // ought to be marked!
    freeMap->Clear((int)dataSectors[i]);
  }
}

//----------------------------------------------------------------------
// FileHeader::FetchFrom
// 	Fetch contents of file header from disk.
//
//	"sector" is the disk sector containing the file header
//----------------------------------------------------------------------

void FileHeader::FetchFrom(int sector) {
  synchDisk->ReadSector(sector, (char *)this);
}

//----------------------------------------------------------------------
// FileHeader::WriteBack
// 	Write the modified contents of the file header back to disk.
//
//	"sector" is the disk sector to contain the file header
//----------------------------------------------------------------------

void FileHeader::WriteBack(int sector) {
  synchDisk->WriteSector(sector, (char *)this);
}

//----------------------------------------------------------------------
// FileHeader::ByteToSector
// 	Return which disk sector is storing a particular byte within the file.
//      This is essentially a translation from a virtual address (the
//	offset in the file) to a physical address (the sector where the
//	data at the offset is stored).
//
//	"offset" is the location within the file of the byte in question
//----------------------------------------------------------------------

int FileHeader::ByteToSector(int offset) {
  int sectorIdx = offset / SectorSize;
  if (sectorIdx >= NumDirect) {
    FileHeader *nxt = new FileHeader;
    if (nextHeaderSector == -1) {
      printf("The offset %d is too large.\n");
      ASSERT(0);
    }
    nxt->FetchFrom(nextHeaderSector);
    int sector = nxt->ByteToSector(offset - NumDirect * SectorSize);
    delete nxt;
    return sector;
  } else {
    return (dataSectors[sectorIdx]);
  }
}

//----------------------------------------------------------------------
// FileHeader::FileLength
// 	Return the number of bytes in the file.
//----------------------------------------------------------------------

int FileHeader::FileLength() { return numBytes; }

void FileHeader::PrintBlocks() {
  for (int i = 0; i < min(numSectors, NumDirect); i++)
    printf("%d ", dataSectors[i]);
  printf("\n\t\t");
}

void FileHeader::PrintContent() {
  int i, j, k;
  char *data = new char[SectorSize];
  for (i = k = 0; i < min(NumDirect, numSectors); i++) {
    synchDisk->ReadSector(dataSectors[i], data);
    for (j = 0; (j < SectorSize) && (k < numBytes); j++, k++) {
      if ('\040' <= data[j] && data[j] <= '\176') // isprint(data[j])
        printf("%c", data[j]);
      else
        printf("\\%x", (unsigned char)data[j]);
    }
    printf("\n");
  }
  delete[] data;
}

//----------------------------------------------------------------------
// FileHeader::Print
// 	Print the contents of the file header, and the contents of all
//	the data blocks pointed to by the file header.
//----------------------------------------------------------------------

void FileHeader::Print() {
  printf("FileHeader contents:\n");
  printf("\tFile size: %d\n", numBytes);
  printf("\tFile blocks:");
  PrintBlocks();
  int nxtSector = nextHeaderSector;
  while (nxtSector != -1) {
    FileHeader *nxt = new FileHeader;
    nxt->FetchFrom(nxtSector);
    nxt->PrintBlocks();
    nxtSector = nxt->nextHeaderSector;
    ASSERT(nxtSector != nextHeaderSector);
    delete nxt;
  }
  printf("\n\tCreate Time: %s\tLast Access Time: %s\tLast Modify Time:%s",
         asctime(localtime(&createTime)), asctime(localtime(&lastAccessTime)),
         asctime(localtime(&lastModifyTime)));
  printf("File contents:\n");
  PrintContent();
  nxtSector = nextHeaderSector;
  while (nxtSector != -1) {
    FileHeader *nxt = new FileHeader;
    nxt->FetchFrom(nxtSector);
    // nxt->PrintContent();
    nxtSector = nxt->nextHeaderSector;
    delete nxt;
  }
}

bool FileHeader::Reallocate(BitMap *freeMap, int newSize) {
  int newNumSectors = divRoundUp(newSize, SectorSize);
  if (newNumSectors <= numSectors) {
    numBytes = newSize;
    return TRUE; // Do not need extend
  }
  int oldTrueSectors = numSectors + divRoundUp(numSectors, NumDirect) - 1;
  int newTrueSectors = newNumSectors + divRoundUp(newNumSectors, NumDirect) - 1;
  int extendTrueSectors = newTrueSectors - oldTrueSectors;
  if (freeMap->NumClear() < extendTrueSectors)
    return FALSE; // not enough space
  numBytes = newSize;
  if (numSectors > NumDirect) { // 调整大小前已经有多个文件头，递归找到最后一个
    numSectors = newNumSectors;
    FileHeader *nxt = new FileHeader;
    nxt->FetchFrom(nextHeaderSector);
    ASSERT(nxt->Reallocate(freeMap, newSize - NumDirect * SectorSize));
    nxt->WriteBack(nextHeaderSector);
    delete nxt;
    return TRUE;
  } else { // 未扩展大小前最后一个文件头
    for (int i = numSectors; i < min(newNumSectors, NumDirect); i++) {
      dataSectors[i] = freeMap->Find();
    }
    numSectors = newNumSectors;
    if (newNumSectors > NumDirect) {
      // Need to allocate extra header
      nextHeaderSector = freeMap->Find();
      DEBUG('f', "Allocate extra header at %d\n", nextHeaderSector);
      FileHeader *nxt = new FileHeader;
      ASSERT(nxt->Allocate(freeMap, newSize - NumDirect * SectorSize));
      nxt->WriteBack(nextHeaderSector);
      delete nxt;
    }
    return TRUE;
  }
  return FALSE;
}
