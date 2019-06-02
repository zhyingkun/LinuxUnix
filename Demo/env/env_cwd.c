#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for chdir

int main(int argc, char* argv[]) {
  printf("Start...\n");
  char* pwd = getenv("PWD");
  printf("$PWD: %s\n", pwd);
  char buffer[1024];
  getcwd(buffer, 1024);
  printf("getcwd: %s\n", buffer);
  chdir("/etc");
  printf("After chdir syscall\n");
  pwd = getenv("PWD");
  printf("$PWD: %s\n", pwd);
  getcwd(buffer, 1024);
  printf("getcwd: %s\n", buffer);
  printf("End\n");
  return 0;
}
