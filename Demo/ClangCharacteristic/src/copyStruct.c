#include <stdio.h>

struct a {
  char b;
  int c;
  char* p;
};

void printStructA(struct a sa) {
  printf("b: %c, c: %d, p: %c\n", sa.b, sa.c, *sa.p);
}

int copystruct_main(int argc, char* argv[]) {
  printf("__FILE__:%s, __LINE__:%d\n", __FILE__, __LINE__);
  char AA = 'A';
  char BB = 'B';
  printf("Start...\n");
  struct a vara, varb, varc;
  vara.b = 'a';
  vara.c = 12;
  vara.p = &AA;
  varb.b = 'b';
  varb.c = 13;
  varb.p = &BB;
  printf("AA: %c, BB: %c\n", AA, BB);
  printStructA(vara);
  printStructA(varb);
  varc = vara;
  vara = varb;
  printf("AA: %c, BB: %c\n", AA, BB);
  printStructA(vara);
  printStructA(varb);
  struct a* pVara = &vara;
  struct a* pVarc = &varc;
  *pVara = *pVarc;
  printStructA(vara);
  printStructA(varb);
  return 0;
}
