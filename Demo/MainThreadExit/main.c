#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static char* argv0 = NULL;
static char* envp0 = NULL;
static int* pMainStack = NULL;
static pthread_t mainThread;

void* threadStart(void* ptr) {
  sleep(1);
  // pthread_join(mainThread, NULL);
  printf("In thread: %s %s %d\n", argv0, envp0, *pMainStack);
  fflush(stdout);
  // sleep(1);
  return NULL;
}

void runAtExit() {
  printf("At Exit Now\n");
  fflush(NULL);
}

int main(int argc, char* argv[], char** envp) {
  argv0 = argv[0];
  envp0 = envp[0];
  int mainStack = 42;
  pMainStack = &mainStack;
  atexit(runAtExit);
  mainThread = pthread_self();
  pthread_t tid;
  printf("In Main Thread, create thread now\n");
  int ret = pthread_create(&tid, NULL, threadStart, NULL);
  printf("In Main Thread, pthread_create ret: %d\n", ret);
  printf("In Main Thread, main thread exit now\n");
  fflush(stdout);
  pthread_exit(NULL);
  // pthread_join(tid, NULL);
  // printf("Now the thread is exit");
  // fflush(NULL);
  // sleep(20);
  return 0;
}
