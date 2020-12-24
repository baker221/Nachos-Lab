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
  numBytes = fileSize;
  numSectors = divRoundUp(fileSize, SectorSize);
  DEBUG('f', "Allocate NumBytes: %d, NumSectors: %d\n", numBytes, numSectors);
  if (freeMap->NumClear() < numSectors + divRoundUp(numSectors, NumDirect) -
                                1) { // 加上额外的 header 块数
    return FALSE;                    // not enough space
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
  printf("\n");
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
    nxt->FetchFrom(nextHeaderSector);
    nxt->PrintBlocks();
    nxtSector = nxt->nextHeaderSector;
    delete nxt;
  }
  printf("\tCreate Time: %s\tLast Access Time: %s\tLast Modify Time:%s",
         asctime(localtime(&createTime)), asctime(localtime(&lastAccessTime)),
         asctime(localtime(&lastModifyTime)));
  printf("File contents:\n");
  PrintContent();
  nxtSector = nextHeaderSector;
  while (nxtSector != -1) {
    FileHeader *nxt = new FileHeader;
    nxt->FetchFrom(nextHeaderSector);
    nxt->PrintContent();
    nxtSector = nxt->nextHeaderSector;
    delete nxt;
  }
}
