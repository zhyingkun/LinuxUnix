#include <stdio.h>

int (*pf)(void);

int f(void) {
  return 10;
}

int (*genf(void))(void) {
  return f;
}
int cfuncpointer_main(int argc, char* argv[]) {
  printf("__FILE__:%s, __LINE__:%d\n", __FILE__, __LINE__);
  pf = f;
  int (*localFunc)(void) = genf();
  printf("result:%d\n", (***********************pf)() + localFunc() + genf()());
  return 0;
}
