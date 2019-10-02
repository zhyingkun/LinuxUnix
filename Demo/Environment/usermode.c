#include <stdio.h>
#include <stdlib.h> // for getenv setenv
// extern char** environ;
int main(int argc, char* argv[]) {
  printf("Start...\n");
  fflush(stdout);
  char* path = getenv("PATH");
  printf("$PATH: %s\n", path);
  fflush(stdout);
  setenv("HELLO", "WORLD", 1);
  char* hello = getenv("HELLO");
  printf("$HELLO: %s\n", hello);
  fflush(stdout);
  printf("End\n");
  fflush(stdout);
  return 0;
}
