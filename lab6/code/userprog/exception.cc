// exception.cc
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "syscall.h"
#include "system.h"

void exec_func(int tname) {
  char *name = (char *)tname;
  printf("Try to open Executable file %s.\n", name);
  OpenFile *executable = fileSystem->Open(name);
  AddrSpace *space;
  if (executable == NULL) {
    printf("Unable to open file %s\n", name);
    return;
  }
  space = new AddrSpace(executable);
  currentThread->space = space;
  delete executable;

  space->InitRegisters();
  space->RestoreState();
  machine->Run();
}

void fork_func(int arg) {
  machine->WriteRegister(PrevPCReg, PCReg);
  machine->WriteRegister(PCReg, arg);
  machine->WriteRegister(NextPCReg, arg + 4);
  machine->Run();
}

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2.
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions
//	are in machine.h.
//----------------------------------------------------------------------

void ExceptionHandler(ExceptionType which) {
  int type = machine->ReadRegister(2);

  if ((which == SyscallException) && (type == SC_Halt)) {
    DEBUG('a', "Shutdown, initiated by user program.\n");
    interrupt->Halt();
  } else if ((which == SyscallException) && (type == SC_Create)) {
    printf("Syscall Create.\n");
    int address = machine->ReadRegister(4);
    int len = 0;
    int success = TRUE;
    while (success) {
      machine->ReadMem(address++, 1, &success);
      len++;
    }
    char *name = new char[len + 1];
    address -= len;
    for (int i = 0; i < len; i++) {
      int t;
      machine->ReadMem(address + i, 1, &t);
      name[i] = (char)t;
    }
    name[len] = '\0';
    fileSystem->Create(name, 100);
    machine->UpdatePC();
  } else if ((which == SyscallException) && (type == SC_Open)) {
    printf("Syscall Open.\n");
    int address = machine->ReadRegister(4);
    int len = 0;
    int success = TRUE;
    while (success) {
      machine->ReadMem(address++, 1, &success);
      len++;
    }
    char *name = new char[len + 1];
    address -= len;
    for (int i = 0; i < len; i++) {
      int t;
      machine->ReadMem(address + i, 1, &t);
      name[i] = (char)t;
    }
    name[len] = '\0';
    OpenFile *openfile = fileSystem->Open(name);
    machine->WriteRegister(2, (int)openfile);
    machine->UpdatePC();
  } else if ((which == SyscallException) && (type == SC_Close)) {
    printf("Syscall Close.\n");
    int id = machine->ReadRegister(4);
    OpenFile *openfile = (OpenFile *)id;
    delete openfile;
    machine->UpdatePC();
  } else if ((which == SyscallException) && (type == SC_Write)) {
    printf("Syscall Write.\n");
    int address = machine->ReadRegister(4); // buffer address
    int size = machine->ReadRegister(5);    // size
    int id = machine->ReadRegister(6);      // id
    char *buffer = new char[size];
    for (int i = 0; i < size; i++) {
      int t;
      machine->ReadMem(address + i, 1, &t);
      buffer[i] = (char)t;
    }
    if (id == 1) {
      for (int i = 0; i < size; i++)
        putchar(buffer[i]);
    } else {
      OpenFile *openfile = (OpenFile *)id;
      openfile->Write(buffer, size);
    }
    machine->UpdatePC();
  } else if ((which == SyscallException) && (type == SC_Read)) {
    printf("Syscall Read.\n");
    int address = machine->ReadRegister(4); // buffer address
    int size = machine->ReadRegister(5);    // size
    int id = machine->ReadRegister(6);      // id
    int result;
    char *buffer = new char[size];
    if (id == 0) {
      for (int i = 0; i < size; i++)
        buffer[i] = getchar();
      result = size;
    } else {
      OpenFile *openfile = (OpenFile *)id;
      result = openfile->Read(buffer, size);
    }
    for (int i = 0; i < result; i++) {
      machine->WriteMem(address + i, 1, (int)buffer[i]);
    }
    machine->WriteRegister(2, result);
    machine->UpdatePC();
  } else if ((which == SyscallException) && (type == SC_Exec)) {
    printf("Syscall Exec.\n");
    int address = machine->ReadRegister(4);
    int success = TRUE;
    int len = 0;
    while (success) {
      machine->ReadMem(address++, 1, &success);
      len++;
    }
    char *name = new char[len + 1];
    address -= len;
    for (int i = 0; i < len; i++) {
      int t;
      machine->ReadMem(address + i, 1, &t);
      name[i] = (char)t;
    }
    name[len] = '\0';
    Thread *newThread = new Thread("newThread");
    newThread->Fork(exec_func, (void *)name);
    machine->WriteRegister(2, (newThread->getThreadID()));
    machine->UpdatePC();
  } else if ((which == SyscallException) && (type == SC_Fork)) {
    printf("Syscall Fork.\n");
    // currentThread->SaveUserState();
    int address = machine->ReadRegister(4);
    Thread *thread = new Thread("True Fork Thread");
    thread->space = new AddrSpace();
    thread->space->AddrSpaceCopy(currentThread->space);
    thread->Fork(fork_func, (void *)address);
    // currentThread->RestoreUserState();
    machine->UpdatePC();
  } else if ((which == SyscallException) && (type == SC_Yield)) {
    printf("Syscall Yield.\n");
    machine->UpdatePC();
    currentThread->Yield();
  } else if ((which == SyscallException) && (type == SC_Join)) {
    printf("Syscall Join.\n");
    int tid = machine->ReadRegister(4);
    while (Threads[tid]) {
      currentThread->Yield();
    }
    machine->UpdatePC();
  } else if ((which == SyscallException) && (type == SC_Exit)) {
    printf("Syscall Exit.\n");
    int status = machine->ReadRegister(4);
    printf("thread %d exit with status %d.\n", currentThread->getThreadID(), status);
    machine->UpdatePC();
    currentThread->Finish();
  } else {
    printf("Unexpected user mode exception %d %d\n", which, type);
    ASSERT(FALSE);
  }
}
