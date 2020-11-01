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
        // ljl begin
        printf(
            "*** thread named \"%s\" UserID %d ThreadID %d looped %d times\n",
            currentThread->getName(), currentThread->getUserID(),
            currentThread->getThreadID(), num);
        // ljl end
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
    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

// ljl begin
void ThreadTest2() {
    DEBUG('t', "Entering ThreadTest2");

    for (int i = 1; i < 150; i++) {
        Thread *t = new Thread("forked thread");
        printf("*** thread named \"%s\" UserID %d ThreadID %d created\n",
               t->getName(), t->getUserID(),
               t->getThreadID());
    }
}

void TSPrint(int which) {
    printf("------TS start----\n");
    currentThread->Print();
    scheduler->Print();
    printf("------TS end------\n");
    currentThread->Yield();
}

void ThreadTest3() {
    DEBUG('t', "Entering ThreadTest3");
    for (int i = 1; i < 10; i++) {
        Thread *t = new Thread("forked thread");
        // t->Print();
        t->Fork(TSPrint, 0);
    }
}
// ljl end

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void ThreadTest() {
    switch (testnum) {
        case 1:
            ThreadTest1();
            break;
        // ljl begin
        case 2:
            ThreadTest2();
            break;
        case 3:
            ThreadTest3();
            break;
        // ljl end
        default:
            printf("No test specified.\n");
            break;
    }
}
