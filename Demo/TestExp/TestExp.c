#include <stdio.h>
#include <math.h>

int main(int argc, const char* argv[]) {
  int n = 1;
  for (int size = 0; size >= 0; size++) {
    if (((size + 1) ^ size) > size) {
      printf("size: %d, 2^n: %s\n", size, size == n - 1 ? "YES" : "NO");
      fflush(NULL);
      n *= 2;
    }
  }
  return 0;
}
