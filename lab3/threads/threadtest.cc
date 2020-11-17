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
#include "synch.h"
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

// begin semaphore reader-writer problem
// reader first
int rCnt;
Semaphore *mutex, *w;
int data;

void semaphore_reader(int which) {
  while (true) {
    mutex->P();
    rCnt++;
    if (rCnt == 1) {
      printf("reader %d is the first reader waiting for reading\n", which);
      w->P();
    }
    mutex->V();
    // read something here
    printf("reader %d reads data value is %d\n", which, data);
    mutex->P();
    rCnt--;
    if (rCnt == 0) {
      w->V();
      printf("reader %d is the last leaving reader\n", which);
    }
    mutex->V();
  }
}
void semaphore_writer(int which) {
  while (true) {
    printf("writer %d is waiting for writing\n", which);
    w->P();
    // write something here
    int data_old = data;
    data += 1;
    printf("writer %d change data from %d to %d\n", which, data_old, data);
    w->V();
    printf("writer %d leaves\n", which);
  }
}
void ThreadTest_Semaphore_rw() {
  DEBUG('t', "Entering ThreadTest_Semaphore_rw");
  rCnt = 0;
  data = 0;
  mutex = new Semaphore("mutex", 1);
  w = new Semaphore("w", 1);
  for (int i = 0; i < 3; i++) {
    Thread *t = new Thread("reader");
    t->Fork(semaphore_reader, (void *)i);
  }
  for (int i = 0; i < 2; i++) {
    Thread *t = new Thread("writer");
    t->Fork(semaphore_writer, (void *)i);
  }
}
// end semaphore reader-writer problem

// begin conditon reader-writer problem
// reader first
int AR; // of active readers
int AW; // of active writers
int WR; // of waiting readers
int WW; // of waiting writers
Lock *lock;
Condition *okToRead;
Condition *okToWrite;

void reader(int which) {
  while (true) {
    lock->Acquire();
    while (AW > 0) {
      printf("reader %d is waiting others writing.\n", which);
      WR++;
      okToRead->Wait(lock);
      WR--;
    }
    AR++;
    lock->Release();
    printf("reader reads data value is %d\n", data);
    lock->Acquire();
    AR--;
    if (((AR + WR) == 0) && (WW > 0)) {
      printf("reader %d is the last leaving reader.\n", which);
      okToWrite->Signal(lock);
    }
    lock->Release();
  }
}
void writer(int which) {
  while (true) {
    lock->Acquire();
    while ((AR + AW) > 0) {
      printf("writer %d is waiting others reading/writing.\n", which);
      WW++;
      okToWrite->Wait(lock);
      WW--;
    }
    AW++;
    lock->Release();
    int data_old = data;
    data += 1;
    printf("writer change data from %d to %d\n", data_old, data);
    lock->Acquire();
    AW--;
    if (WR > 0) {
      printf("writer %d is trying to wake up a reader\n", which);
      okToRead->Signal(lock);
    } else if (WW > 0) {
      printf("writer %d is trying to wake up a writer\n", which);
      okToWrite->Signal(lock);
    }
    lock->Release();
  }
}
void ThreadTest_rw() {
  DEBUG('t', "Entering ThreadTest_rw");
  data = 0;
  AR = 0;
  AW = 0;
  WR = 0;
  WW = 0;
  lock = new Lock("lock");
  okToRead = new Condition("okToRead");
  okToWrite = new Condition("okToWrite");
  for (int i = 0; i < 1; i++) { // reader num
    Thread *t = new Thread("reader");
    t->Fork(reader, (void *)i);
  }
  for (int i = 0; i < 2; i++) {
    Thread *t = new Thread("writer");
    t->Fork(writer, (void *)i);
  }
}
// end conditon reader-writer problem

// begin barrier
int totalNum;
int curNum;
Lock *barrierLock;
Condition *barrierCond;
void barrier(int which) {
  printf("thread %d say hello\n", which);
  barrierLock->Acquire();
  curNum++;
  if (curNum < totalNum) {
    printf("thread %d waiting for others\n", which);
    barrierCond->Wait(barrierLock);
  } else if (curNum == totalNum) {
    printf("thread %d wake up other threads\n", which);
    barrierCond->Broadcast(barrierLock);
  }
  barrierLock->Release();
  printf("thread %d say goodbye\n", which);
}
void ThreadTest_barrier() {
  DEBUG('t', "Entering ThreadTest_barrier");
  totalNum = 5;
  curNum = 0;
  barrierLock = new Lock("barrierLock");
  barrierCond = new Condition("barrierCond");
  for (int i = 0; i < totalNum; i++) { // reader num
    Thread *t = new Thread("barrier");
    t->Fork(barrier, (void *)i);
  }
  return;
}
// end barrier

// begin rwlock
RWLock *rwlock;
void rwThread(int which) {
  if (which <= 2) { // reader
    for (int i = 0; i < 10; i++) {
      printf("reader %d prepare to read\n", which);
      rwlock->readerIn();
      printf("reader %d read data is %d\n", which, data);
      currentThread->Yield(); // wait a moment
      rwlock->readerOut();
    }
  } else {
    for (int i = 0; i < 5; i++) {
      printf("writer %d prepare to write\n", which);
      rwlock->writerIn();
      int olddata = data;
      data++;
      printf("writer %d change data from %d to %d\n", which, olddata, data);
      currentThread->Yield();
      rwlock->writerOut();
    }
  }
}
void ThreadTest_rwlock() {
  DEBUG('t', "Entering ThreadTest_rwlock");
  data = 0;
  rwlock = new RWLock("rwlock");
  for (int i = 0; i < 5; i++) {
    char *name = new char[30];
    sprintf(name, "Thread %d", i);
    (new Thread(name))->Fork(rwThread, (void *)i);
  }
}
// end rwlock

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void ThreadTest() {
  // DebugInit("t");
  switch (testnum) {
  case 1:
    ThreadTest1();
    break;
  case 2:
    ThreadTest_Semaphore_rw();
    break;
  case 3:
    ThreadTest_rw();
    break;
  case 4:
    ThreadTest_barrier();
    break;
  case 5:
    ThreadTest_rwlock();
    break;
  default:
    printf("No test specified.\n");
    break;
  }
}
