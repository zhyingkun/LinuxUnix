#include <stdio.h>

int cal_main(int argc, char* argv[]) {
  printf("__FILE__:%s, __LINE__:%d\n", __FILE__, __LINE__);
  int a = 10;
  int b = (a++) * 2 + (++a) * 2;
  int c = 2;
  int d = (++c > 2) && a + 1;
  c = 2;
  int e = (c++ > 2) && a + 1;
  c = 2;
  int f = (c > 2) && c++;
  c = 2;
  int g = (c > 2) && ++c;
  printf("a: %d b: %d\n", a, b);
  printf("c:%d, d:%d, e:%d, f:%d, g:%d\n", c, d, e, f, g);
  return 0;
}
