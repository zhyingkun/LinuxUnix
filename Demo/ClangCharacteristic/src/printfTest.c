#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Kernel/stdarg.h>

void printfTest() {
  int num = 0;
  num = printf("printf: %d\n", 20);

  char bufs[30];
  num = sprintf(bufs, "sprintf: %d", 20);
  printf("%s, num: %d\n", bufs, num);

  char bufsn[13];
  num = snprintf(bufsn, 13, "snprintf: %d", 20);
  printf("%s, num: %d\n", bufsn, num);

  char* bufAPtr = NULL;
  num = asprintf(&bufAPtr, "asprintf: %d", 20);
  printf("%s, num: %d\n", bufAPtr, num);
  free(bufAPtr);

  num = fprintf(stdout, "fprintf: %d\n", 20);

  num = dprintf(STDOUT_FILENO, "dprintf: %d\n", 20);
  return;
}

void vprintfTest(const char* format, ...) {
  va_list ap;
  va_start(ap, format);

  vprintf(format, ap);

  int num = 0;
  char bufs[30];
  num = vsprintf(bufs, "vsprintf: %d", ap);
  printf("%s, num: %d\n", bufs, num);

  char bufsn[14];
  num = vsnprintf(bufsn, 14, "vsnprintf: %d", ap);
  printf("%s, num: %d\n", bufsn, num);

  char* bufAPtr = NULL;
  num = vasprintf(&bufAPtr, "vasprintf: %d", ap);
  printf("%s, num: %d\n", bufAPtr, num);
  free(bufAPtr);

  num = vfprintf(stdout, "vfprintf: %d\n", ap);

  num = vdprintf(STDOUT_FILENO, "vdprintf: %d\n", ap);

  va_end(ap);
  return;
}

int printf_main(int argc, char const* argv[]) {
  printf("__FILE__:%s, __LINE__:%d\n", __FILE__, __LINE__);
  printfTest();
  printf("\n");
  vprintfTest("vprintf: %d\n", 20, 21, 22, 23, 24, 25);
  return 0;
}
