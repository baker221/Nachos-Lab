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
#include "machine.h"
#include "syscall.h"
#include "system.h"

// FIFO Replace
void FIFOReplace(TranslationEntry page) {
  printf("Using FIFO Replace Algorithm!\n");
  int replaceIdx = -1;
  for (int i = 0; i < TLBSize; i++) {
    if (machine->tlb[i].valid == FALSE) {
      replaceIdx = i;
      break;
    }
  }
  if (replaceIdx == -1) { // FIFO
    for (int i = 1; i < TLBSize; i++) {
      machine->tlb[i - 1] = machine->tlb[i];
    }
    replaceIdx = TLBSize - 1;
  }
  machine->tlb[replaceIdx] = page;
}

// LRU Replace
void LRUReplace(TranslationEntry page) {
  printf("Using LRU Replace Algorithm!\n");
  int replaceIdx = -1;
  for (int i = 0; i < TLBSize; i++) {
    machine->tlbUseCounter[i]++;
  }
  for (int i = 0; i < TLBSize; i++) {
    if (machine->tlb[i].valid == FALSE) {
      replaceIdx = i;
      break;
    }
  }
  if (replaceIdx == -1) { // LRU
    int maxm = 0;
    for (int i = 0; i < TLBSize; i++) {
      if (machine->tlbUseCounter[i] > maxm) {
        maxm = machine->tlbUseCounter[i];
        replaceIdx = i;
      }
    }
  }
  machine->tlb[replaceIdx] = page;
  machine->tlbUseCounter[replaceIdx] = 0;
}

// Random Replace
void RandomReplace(TranslationEntry page) {
  printf("Using Random Replace Algorithm!\n");
  int replaceIdx = -1;
  for (int i = 0; i < TLBSize; i++) {
    machine->tlbUseCounter[i]++;
  }
  for (int i = 0; i < TLBSize; i++) {
    if (machine->tlb[i].valid == FALSE) {
      replaceIdx = i;
      break;
    }
  }
  if (replaceIdx == -1) { // Random
    replaceIdx = Random() % TLBSize;
  }
  machine->tlb[replaceIdx] = page;
}

void TLBMissHandler(int BadVAddr) {
  unsigned int vpn = (unsigned)BadVAddr / PageSize;
  TranslationEntry page = machine->pageTable[vpn];
  if (!page.valid) {
    printf("True page table page fault happens!\n");
    ASSERT(FALSE);
  }
  // FIFOReplace(page);
  LRUReplace(page);
  // RandomReplace(page);
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

  if (which == PageFaultException) {
    if (machine->tlb == NULL) {
      printf("Page table page fault.\n");
      ASSERT(FALSE);
    } else {
      printf("TLB miss!\n");
      int BadVAddr = machine->ReadRegister(BadVAddrReg);
      TLBMissHandler(BadVAddr);
    }
    return;
  } else if ((which == SyscallException) &&
             (type == SC_Halt || type == SC_Exit)) {
    DEBUG('a', "Shutdown, initiated by user program.\n");
    printf("tlbTotalCount is %d, tlbMissCount is %d, tlbMissRate is %f\%\n",
           machine->tlbTotalCount, machine->tlbMissCount,
           100.0 * machine->tlbMissCount / machine->tlbTotalCount);
    machine->freeMem();
    interrupt->Halt();
  } else {
    printf("Unexpected user mode exception %d %d\n", which, type);
    ASSERT(FALSE);
  }
}
