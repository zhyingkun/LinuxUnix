#include <stdio.h>

// int max(int a, int b) {
//   if (a > b) {
//     return a;
//   }
//   return b;
// }
#define max(a, b) ((a) > (b) ? (a) : (b))

int vectorMax(int* vector, int size) {
  if (size == 1) {
    return vector[0];
  }
  // In here, max use Macro may be slower then Function
  // Because vectorMax function called more then once
  return max(vector[size - 1], vectorMax(vector, size - 1));
}

int main(int argc, char* argv[]) {
  int vector[] = {3, -2, -2, 5, 6, -2, 3, -4, 7, 2, -1, -4, 3, 9, -2, -7, 4};
  printf("Max value of Vector: %d\n", vectorMax(vector, sizeof(vector) / sizeof(int)));
  return 0;
}
