#include "copyright.h"

#include "console.h"
#include "synch.h"

class SynchConsole {
public:
  SynchConsole(char *readFile, char *writeFile);
  ~SynchConsole();
  void PutChar(char ch);
  char GetChar();
  void WriteDone();
  void ReadAvail();

private:
  Console *console;
  Semaphore *readAvail, *writeDone;
  Lock *lock;
};
