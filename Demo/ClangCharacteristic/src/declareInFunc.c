#include <stdio.h>

int declareinfunc_main(int argc, char* argv[]) {
  printf("__FILE__:%s, __LINE__:%d\n", __FILE__, __LINE__);
  void printHello();
  printHello();
  void printNice();
  printNice();
  return 0;
}

void printNice() {
  printf("Nice\n");
} // printHelo(); }
void printHello() {
  printf("Hello\n");
}
