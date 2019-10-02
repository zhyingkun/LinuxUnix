#include <stdio.h>
#include <stdlib.h> // for getenv setenv
#include <string.h>
extern char** environ;
int main(int argc, char* argv[], char** envp) {
  printf("Start...\n");
  for (int i = 0; envp[i] != NULL; i++) {
    if (0 == strncmp(envp[i], "PATH", 4)) {
      printf("PATH in envp: %x\n", envp[i]);
      break;
    }
  }
  char* path = getenv("PATH");
  printf("getenv PATH: %x, environ: %x\n", path, environ);
  setenv("PATH", "NoPath", 1);
  path = getenv("PATH");
  printf("getenv PATH: %x, environ: %x\n", path, environ);
  setenv("HELLO", "WORLD", 1);
  setenv("HELLO1", "WORLD1", 1);
  setenv("HELLO2", "WORLD2", 1);
  setenv("HELLO3", "WORLD3", 1);
  setenv("HELLO4", "WORLD4", 1);
  path = getenv("PATH");
  printf("getenv PATH: %x, environ: %x\n", path, environ);
  printf("End\n");
  return 0;
}
