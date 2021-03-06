#include <stdbool.h>
#include <stdio.h>

void print1toN(int n) {
  for (int i = 0; i < n; i++) {
    printf("In Print: %d\n", i+1);
  }
}
void getPara() {
  printf("In getPara Now...\n");
  // do something
}
void doCompile() {
  printf("In doCompile Now...\n");
  // do something
}
void uploadResult() {
  printf("In uploadResult Now...\n");
  // do something
}
void remoteCompile() {
  getPara();
  doCompile();
  uploadResult();
}
static int procCnt = 0;
bool doNext() {
  switch (procCnt) {
  case 0:
    getPara();
    procCnt++;
    return true;
  case 1:
    doCompile();
    procCnt++;
    return true;
  case 2:
    uploadResult();
    procCnt++;
    return false;
  default:
    // error, now the process is finish
    fprintf(stderr, "The process has finished\n");
    return false;
  }
}

int main(int argc, char* argv[]) {
  print1toN(3);
  remoteCompile();
  // for user:
  while (doNext())
    ;
  return 0;
}
