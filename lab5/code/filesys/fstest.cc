// fstest.cc
//	Simple test routines for the file system.
//
//	We implement:
//	   Copy -- copy a file from UNIX to Nachos
//	   Print -- cat the contents of a Nachos file
//	   Perftest -- a stress test for the Nachos file system
//		read and write a really large file in tiny chunks
//		(won't work on baseline system!)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"

#include "disk.h"
#include "filesys.h"
#include "stats.h"
#include "system.h"
#include "thread.h"
#include "utility.h"

#define TransferSize 10 // make it small, just to be difficult

//----------------------------------------------------------------------
// Copy
// 	Copy the contents of the UNIX file "from" to the Nachos file "to"
//----------------------------------------------------------------------

void Copy(char *from, char *to) {
  FILE *fp;
  OpenFile *openFile;
  int amountRead, fileLength;
  char *buffer;

  // Open UNIX file
  if ((fp = fopen(from, "r")) == NULL) {
    printf("Copy: couldn't open input file %s\n", from);
    return;
  }

  // Figure out length of UNIX file
  fseek(fp, 0, 2);
  fileLength = ftell(fp);
  fseek(fp, 0, 0);

  // Create a Nachos file of the same length
  DEBUG('f', "Copying file %s, size %d, to file %s\n", from, fileLength, to);
  if (!fileSystem->Create(to, fileLength)) { // Create Nachos file
    printf("Copy: couldn't create output file %s\n", to);
    fclose(fp);
    return;
  }

  openFile = fileSystem->Open(to);
  ASSERT(openFile != NULL);

  // Copy the data in TransferSize chunks
  buffer = new char[TransferSize];
  while ((amountRead = fread(buffer, sizeof(char), TransferSize, fp)) > 0)
    openFile->Write(buffer, amountRead);
  delete[] buffer;

  // Close the UNIX and the Nachos files
  delete openFile;
  fclose(fp);
}

//----------------------------------------------------------------------
// Print
// 	Print the contents of the Nachos file "name".
//----------------------------------------------------------------------

void Print(char *name) {
  OpenFile *openFile;
  int i, amountRead;
  char *buffer;

  if ((openFile = fileSystem->Open(name)) == NULL) {
    printf("Print: unable to open file %s\n", name);
    return;
  }

  buffer = new char[TransferSize];
  while ((amountRead = openFile->Read(buffer, TransferSize)) > 0)
    for (i = 0; i < amountRead; i++)
      printf("%c", buffer[i]);
  delete[] buffer;

  delete openFile; // close the Nachos file
  return;
}

//----------------------------------------------------------------------
// PerformanceTest
// 	Stress the Nachos file system by creating a large file, writing
//	it out a bit at a time, reading it back a bit at a time, and then
//	deleting the file.
//
//	Implemented as three separate routines:
//	  FileWrite -- write the file
//	  FileRead -- read the file
//	  PerformanceTest -- overall control, and print out performance #'s
//----------------------------------------------------------------------

#define FileName "TestFile"
#define Contents "1234567890"
#define ContentSize strlen(Contents)
#define FileSize ((int)(ContentSize * 500))

static void FileWrite() {
  OpenFile *openFile;
  int i, numBytes;

  printf("Sequential write of %d byte file, in %d byte chunks\n", FileSize,
         ContentSize);
  if (!fileSystem->Create(FileName, FileSize)) {
    printf("Perf test: can't create %s\n", FileName);
    return;
  }
  openFile = fileSystem->Open(FileName);
  if (openFile == NULL) {
    printf("Perf test: unable to open %s\n", FileName);
    return;
  }
  for (i = 0; i < FileSize; i += ContentSize) {
    numBytes = openFile->Write(Contents, ContentSize);
    if (numBytes < 10) {
      printf("Perf test: unable to write %s\n", FileName);
      delete openFile;
      return;
    }
  }
  delete openFile; // close file
}

static void FileRead() {
  OpenFile *openFile;
  char *buffer = new char[ContentSize];
  int i, numBytes;

  printf("Sequential read of %d byte file, in %d byte chunks\n", FileSize,
         ContentSize);

  if ((openFile = fileSystem->Open(FileName)) == NULL) {
    printf("Perf test: unable to open file %s\n", FileName);
    delete[] buffer;
    return;
  }
  for (i = 0; i < FileSize; i += ContentSize) {
    numBytes = openFile->Read(buffer, ContentSize);
    if ((numBytes < 10) || strncmp(buffer, Contents, ContentSize)) {
      printf("Perf test: unable to read %s\n", FileName);
      delete openFile;
      delete[] buffer;
      return;
    }
  }
  delete[] buffer;
  delete openFile; // close file
}

void PerformanceTest() {
  printf("Starting file system performance test:\n");
  stats->Print();
  FileWrite();
  FileRead();
  if (!fileSystem->Remove(FileName)) {
    printf("Perf test: unable to remove %s\n", FileName);
    return;
  }
  fileSystem->Print();
  stats->Print();
}

void DynamicTest() {
  fileSystem->Create("dynamic.txt", FileSize);
  OpenFile *openFile;
  int i, numBytes;

  openFile = fileSystem->Open("dynamic.txt");
  if (openFile == NULL) {
    printf("Dynamic test: unable to open %s\n", FileName);
    return;
  }
  printf("Start Writing.\n");
  for (i = 0; i < 2 * FileSize; i += ContentSize) {
    if (i >= 5000 && (i % 100 == 0)) {
      printf("Starting %dth writing \n", i);
    }
    numBytes = openFile->Write(Contents, ContentSize);
    if (numBytes < 10) {
      printf("Perf test: unable to write %s\n", FileName);
      delete openFile;
      return;
    }
  }
  printf("Read disk time is %d, Write disk time is %d\n", stats->numDiskReads,
         stats->numDiskWrites);
  delete openFile; // close file
}

void ReaderThread(int which) {
  int num;
  int numBytes;
  char *buffer = new char[ContentSize];
  OpenFile *openFile = fileSystem->Open("dynamic.txt");
  for (num = 0; num < 5; num++) {
    printf("Thread %d prepare to read.\n", which);
    // numBytes = openFile->Read(buffer, ContentSize);
    currentThread->Yield();
  }
  delete[] buffer;
}

void WriterThread(int which) {
  int num;
  int numBytes;
  OpenFile *openFile = fileSystem->Open("dynamic.txt");
  for (num = 0; num < 5; num++) {
    printf("Thread %d prepare to write.\n", which);
    numBytes = openFile->Write("0987654321", ContentSize);
    currentThread->Yield();
  }
}

void FileRWTest() {
  Thread *t1 = new Thread("forked thread");
  Thread *t2 = new Thread("forked thread");
  Thread *t3 = new Thread("forked thread");
  t1->Fork(ReaderThread, 1);
  t2->Fork(WriterThread, 2);
  t3->Fork(ReaderThread, 3);
  currentThread->Yield();
}

void DeleteThread(int which) {
  OpenFile *openFile = fileSystem->Open("dynamic.txt");
  fileSystem->Remove("dynamic.txt");
}

void FileDelTest() {
  Thread *t1 = new Thread("forked thread");
  Thread *t2 = new Thread("forked thread");
  Thread *t3 = new Thread("forked thread");
  t1->Fork(DeleteThread, 1);
  t2->Fork(DeleteThread, 2);
  t3->Fork(DeleteThread, 3);
  currentThread->Yield();
}

void getDataFromPipe(int dummy) {
  printf("In thread B: reading from pipe to console:\n");
  char *output_data = new char[25];
  printf("Output:");

  fileSystem->ReadPipe(output_data, 24);
  printf("%s\n", output_data);
}

void PipeTest() {
  printf("Starting pipe test:\n");
  printf("In thread A: reading from console to pipe:\n");
  char *input_data = new char[25];
  printf("Input:");
  scanf("%s", input_data);
  fileSystem->WritePipe(input_data, strlen(input_data));
  Thread *t2 = new Thread("Thread B");
  t2->Fork(getDataFromPipe, 0);
}

void MultiDirTest() {
  printf("Starting multi directory test:\n");
  fileSystem->Create("1.txt", 100);
  fileSystem->Create("2.txt", 100);
  fileSystem->CreateDirectory("dir1");
  fileSystem->Create("dir1/3.txt", 100);
  fileSystem->CreateDirectory("dir1/dir2");
  fileSystem->Create("dir1/dir2/4.txt", 100);
  fileSystem->CreateDirectory("dir3");
  fileSystem->CreateDirectory("dir3/pku");
  fileSystem->Create("dir3/pku/xxx.cpp", 100);
  printf("-------------------------\n");
  fileSystem->List();
  fileSystem->List("dir1");
  fileSystem->List("dir1/dir2");
  fileSystem->List("dir3");
  fileSystem->List("dir3/pku");
}