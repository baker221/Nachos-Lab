#include "syscall.h"


int main() {
  char input[15];
  char output[15];
  int fd;
  Create("testFile");
  Read(input, 10, 0);
  fd = Open("testFile");
  Write(input, 10, fd);
  Close(fd);
  fd = Open("testFile");
  Read(output, 10, fd);
  Close(fd);
  Write(output, 10, 1);
  Halt();
}
