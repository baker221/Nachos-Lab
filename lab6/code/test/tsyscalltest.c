#include "syscall.h"

void func() { Create("1.txt"); }

int main() {
  int fd;
  Create("2.txt");
  Fork(func);
  fd = Exec("../test/halt");
  Join(fd);
  Exit(0);
}
