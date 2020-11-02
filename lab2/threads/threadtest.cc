// threadtest.cc
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield,
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "elevatortest.h"
#include "system.h"

// testnum is set in main.cc
int testnum = 1;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void SimpleThread(int which) {
  int num;

  for (num = 0; num < 5; num++) {
    printf("*** thread %d looped %d times\n", which, num);
    currentThread->Yield();
  }
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void ThreadTest1() {
  DEBUG('t', "Entering ThreadTest1");

  Thread *t = new Thread("forked thread");

  t->Fork(SimpleThread, (void *)1);
  SimpleThread(0);
}

// begin ljl
//----------------------------------------------------------------------
// ThreadPriorityTest()
//----------------------------------------------------------------------
void newSimpleThread(int which) {
  int num;

  for (num = 0; num < 5; num++) {
    printf("*** thread %d looped %d times\n", which, num);
  }
}

void ThreadPriorityTest() {
  DEBUG('t', "Entering ThreadPriorityTest");

  Thread *t1 = new Thread("forked thread 1", 1);
  Thread *t2 = new Thread("forked thread 2", 2);
  Thread *t3 = new Thread("forked thread 3", 3);
  Thread *t4 = new Thread("forked thread 4", 4);

  t4->Fork(newSimpleThread, (void *)4);
  t3->Fork(newSimpleThread, (void *)3);
  t2->Fork(newSimpleThread, (void *)2);
  t1->Fork(newSimpleThread, (void *)1);
}
// end ljl

// begin ljl
//----------------------------------------------------------------------
// ThreadRRTest()
//----------------------------------------------------------------------
void SimpleThread_ticks(int which) {
  int num;
  for (num = 0; num < 20; num++) {
    printf("*** thread %d looped %d times, now totalTicks: %d\n", which, num,
           stats->totalTicks);
    interrupt->OneTick();
  }
}
void ThreadRRTest() {
  DEBUG('t', "Entering ThreadRRTest");

  printf("before true rrtest, now ticks: %d\n\n", stats->totalTicks);

  Thread *t1 = new Thread("forked thread 1", 1);
  Thread *t2 = new Thread("forked thread 2", 2);
  Thread *t3 = new Thread("forked thread 3", 3);
  Thread *t4 = new Thread("forked thread 4", 4);

  printf("After new thread, ticks: %d\n\n", stats->totalTicks);

  t4->Fork(SimpleThread_ticks, (void *)4);
  t3->Fork(SimpleThread_ticks, (void *)3);
  t2->Fork(SimpleThread_ticks, (void *)2);
  t1->Fork(SimpleThread_ticks, (void *)1);

  printf("After fork, ticks: %d\n\n", stats->totalTicks);

  scheduler->LastSwitchTick = stats->totalTicks; // update the LastSwitchTick
  currentThread->Yield();
}
// end ljl

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void ThreadTest() {
  switch (testnum) {
  case 1:
    ThreadTest1();
    break;
  case 2:
    ThreadPriorityTest();
    break;
  case 3:
    ThreadRRTest();
    break;
  default:
    printf("No test specified.\n");
    break;
  }
}
