#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
  fclose(stdin);
  for (int i = 1; i < argc; i++) {
    printf("%s ", argv[i]);
  }
  printf("\n");
  fflush(NULL);
  sleep(2);
  printf("In myecho, pid:%d  ppid:%d\n", getpid(), getppid());
  fflush(NULL);
  return 0;
}
