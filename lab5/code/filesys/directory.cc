// directory.cc
//	Routines to manage a directory of file names.
//
//	The directory is a table of fixed length entries; each
//	entry represents a single file, and contains the file name,
//	and the location of the file header on disk.  The fixed size
//	of each directory entry means that we have the restriction
//	of a fixed maximum size for file names.
//
//	The constructor initializes an empty directory of a certain size;
//	we use ReadFrom/WriteBack to fetch the contents of the directory
//	from disk, and to write back any modifications back to disk.
//
//	Also, this implementation has the restriction that the size
//	of the directory cannot expand.  In other words, once all the
//	entries in the directory are used, no more files can be created.
//	Fixing this is one of the parts to the assignment.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "directory.h"
#include "copyright.h"
#include "filehdr.h"
#include "filesys.h"
#include "utility.h"

static void PathParse(char *path, char *dirname, char *others) {
  // char *tmp = new char[strlen(path) + 5];
  // strcpy(tmp, path);
  char *tmp = strdup(path);
  char *split = strchr(tmp, '/');
  if (split == NULL) {
    strcpy(dirname, "");
    strcpy(others, tmp);
  } else {
    *split = '\0';
    strcpy(dirname, tmp);
    strcpy(others, split + 1);
  }
  delete[] tmp;
}

//----------------------------------------------------------------------
// Directory::Directory
// 	Initialize a directory; initially, the directory is completely
//	empty.  If the disk is being formatted, an empty directory
//	is all we need, but otherwise, we need to call FetchFrom in order
//	to initialize it from disk.
//
//	"size" is the number of entries in the directory
//----------------------------------------------------------------------

Directory::Directory(int size) {
  table = new DirectoryEntry[size];
  tableSize = size;
  for (int i = 0; i < tableSize; i++)
    table[i].inUse = FALSE;
}

//----------------------------------------------------------------------
// Directory::~Directory
// 	De-allocate directory data structure.
//----------------------------------------------------------------------

Directory::~Directory() { delete[] table; }

//----------------------------------------------------------------------
// Directory::FetchFrom
// 	Read the contents of the directory from disk.
//
//	"file" -- file containing the directory contents
//----------------------------------------------------------------------

void Directory::FetchFrom(OpenFile *file) {
  (void)file->ReadAt((char *)table, tableSize * sizeof(DirectoryEntry), 0);
}

//----------------------------------------------------------------------
// Directory::WriteBack
// 	Write any modifications to the directory back to disk
//
//	"file" -- file to contain the new directory contents
//----------------------------------------------------------------------

void Directory::WriteBack(OpenFile *file) {
  (void)file->WriteAt((char *)table, tableSize * sizeof(DirectoryEntry), 0);
}

//----------------------------------------------------------------------
// Directory::FindIndex
// 	Look up file name in directory, and return its location in the table of
//	directory entries.  Return -1 if the name isn't in the directory.
//
//	"name" -- the file name to look up
//----------------------------------------------------------------------

int Directory::FindIndex(char *name) {
  for (int i = 0; i < tableSize; i++)
    if (table[i].inUse && !strcmp(table[i].name, name))
      return i;
  return -1; // name not in directory
}

//----------------------------------------------------------------------
// Directory::Find
// 	Look up file name in directory, and return the disk sector number
//	where the file's header is stored. Return -1 if the name isn't
//	in the directory.
//
//	"name" -- the file name to look up
//----------------------------------------------------------------------

int Directory::Find(char *name) {
  DEBUG('f', "Entering directory Find, target name is %s\n", name);
  char *dirname = new char[strlen(name) + 5];
  char *others = new char[strlen(name) + 5];
  PathParse(name, dirname, others);
  if (strlen(dirname) == 0) { // 在当前目录寻找
    int i = FindIndex(name);
    if (i != -1)
      return table[i].sector;
    return -1;
  } else {
    int i = FindIndex(dirname);
    if (i != -1) {
      if (!table[i].isDirectory)
        return -1;
      OpenFile *file = new OpenFile(table[i].sector);
      Directory *dir = new Directory(NumDirEntries);
      dir->FetchFrom(file);
      int ret = dir->Find(others);
      delete file;
      delete dir;
      return ret;
    }
    return -1;
  }
}

//----------------------------------------------------------------------
// Directory::Add
// 	Add a file into the directory.  Return TRUE if successful;
//	return FALSE if the file name is already in the directory, or if
//	the directory is completely full, and has no more space for
//	additional file names.
//
//	"name" -- the name of the file being added
//	"newSector" -- the disk sector containing the added file's header
//----------------------------------------------------------------------

bool Directory::Add(char *name, int newSector, bool isDirectory = FALSE) {
  DEBUG('f', "Entering directory Add, target name is %s\n", name);
  char *dirname = new char[strlen(name) + 5];
  char *others = new char[strlen(name) + 5];
  PathParse(name, dirname, others);
  if (strlen(dirname) == 0) {
    if (FindIndex(name) != -1)
      return FALSE;
    for (int i = 0; i < tableSize; i++) {
      if (!table[i].inUse) {
        table[i].inUse = TRUE;
        table[i].isDirectory = isDirectory;
        table[i].name = name;
        table[i].sector = newSector;
        return TRUE;
      }
    }
    return FALSE; // no space.
  } else {
    int i = FindIndex(dirname);
    if (i != -1) {
      if (!table[i].isDirectory)
        return FALSE;
      OpenFile *file = new OpenFile(table[i].sector);
      Directory *dir = new Directory(NumDirEntries);
      dir->FetchFrom(file);
      bool ret = dir->Add(others, newSector, isDirectory);
      dir->WriteBack(file);
      delete file;
      delete dir;
      return ret;
    }
    return FALSE;
  }
}

//----------------------------------------------------------------------
// Directory::Remove
// 	Remove a file name from the directory.  Return TRUE if successful;
//	return FALSE if the file isn't in the directory.
//
//	"name" -- the file name to be removed
//----------------------------------------------------------------------

bool Directory::Remove(char *name) {
  DEBUG('f', "Entering directory Remove, target name is %s\n", name);
  char *dirname = new char[strlen(name) + 5];
  char *others = new char[strlen(name) + 5];
  PathParse(name, dirname, others);
  if (strlen(dirname) == 0) {
    int i = FindIndex(name);
    if (i == -1)
      return FALSE; // name not in directory
    table[i].inUse = FALSE;
    return TRUE;
  } else {
    int i = FindIndex(dirname);
    if (i != -1) {
      if (!table[i].isDirectory)
        return FALSE;
      OpenFile *file = new OpenFile(table[i].sector);
      Directory *dir = new Directory(NumDirEntries);
      dir->FetchFrom(file);
      bool ret = dir->Remove(others);
      dir->WriteBack(file);
      delete file;
      delete dir;
      return ret;
    }
    return FALSE;
  }
}

//----------------------------------------------------------------------
// Directory::List
// 	List all the file names in the directory.
//----------------------------------------------------------------------

char *timestr(char *s) {
  for (char *c = s; *c; c++)
    *c = (*c == '\n' ? '\0' : *c);
  return s;
}

void Directory::List(char *prefix) {
  printf("Directory List\n");
  printf("| %10s | %20s | %10s | %25s | %25s | %25s |\n", "Name", "Path",
         "Type", "Create Time", "Access Time", "Modify Time");
  for (int i = 0; i < tableSize; i++)
    if (table[i].inUse) {
      char *name = table[i].name;
      char *type = new char[10];
      char *path = new char[30];
      if (table[i].isDirectory)
        strcpy(type, "dir");
      else
        strcpy(type, "file");
      strcpy(path, prefix);
      FileHeader *hdr = new FileHeader;
      hdr->FetchFrom(table[i].sector);

      printf("| %10s | %20s | %10s | %25s | %25s | %25s |\n", name, path, type,
             timestr(asctime(localtime(&hdr->createTime))),
             timestr(asctime(localtime(&hdr->lastAccessTime))),
             timestr(asctime(localtime(&hdr->lastModifyTime))));
      delete hdr;
    }
}

//----------------------------------------------------------------------
// Directory::Print
// 	List all the file names in the directory, their FileHeader locations,
//	and the contents of each file.  For debugging.
//----------------------------------------------------------------------

void Directory::Print() {
  FileHeader *hdr = new FileHeader;

  printf("Directory contents (files):\n");
  for (int i = 0; i < tableSize; i++)
    if (table[i].inUse && !table[i].isDirectory) {
      printf("Name: %s, Sector: %d\n", table[i].name, table[i].sector);
      hdr->FetchFrom(table[i].sector);
      hdr->Print();
    }

  printf("Directory contents (dirs):\n");
  for (int i = 0; i < tableSize; i++)
    if (table[i].inUse && table[i].isDirectory) {
      printf("Name: %s, Sector: %d\n", table[i].name, table[i].sector);
      hdr->FetchFrom(table[i].sector);
      hdr->Print();
      OpenFile *file = new OpenFile(table[i].sector);
      Directory *dir = new Directory(NumDirEntries);
      dir->FetchFrom(file);
      dir->Print();
      delete dir;
      delete file;
    }

  printf("\n");
  delete hdr;
}
