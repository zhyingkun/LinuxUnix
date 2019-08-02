#include <stdio.h>
#include <stdlib.h>

void rotateLeft1(int* vector, int size, int num) {
  int* tmpVec = (int*)malloc(sizeof(int) * num);
  for (int i = 0; i < num; i++) {
    tmpVec[i] = vector[i];
  }
  for (int i = 0; i < size - num; i++) {
    vector[i] = vector[i + num];
  }
  for (int i = 0; i < num; i++) {
    vector[size - num + i] = tmpVec[i];
  }
  free(tmpVec);
}
void rotateLeft2(int* vector, int size, int num) {
  for (int currentIndex = 0, loop = 0; loop < size; currentIndex++) {
    int tmpVal = vector[currentIndex];
    int index = currentIndex;
    while (1) {
      int nextIndex = (index + num) % size;
      if (nextIndex == currentIndex) {
        vector[index] = tmpVal;
        loop++;
        break;
      }
      vector[index] = vector[nextIndex];
      loop++;
      index = nextIndex;
    }
  }
}
void reverseVector(int* vector, int start, int end) {
  for (; start < end; start++, end--) {
    int tmp = vector[start];
    vector[start] = vector[end];
    vector[end] = tmp;
  }
}
void rotateLeft3(int* vector, int size, int num) {
  reverseVector(vector, 0, num - 1);
  reverseVector(vector, num, size - 1);
  reverseVector(vector, 0, size - 1);
}
void printVector(int* vector, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");
}
#define SizeOfVector 10
int main(int argc, char* argv[]) {
  int vector[SizeOfVector];
  for (int i = 0; i < SizeOfVector; i++) {
    vector[i] = i;
  }
  printVector(vector, SizeOfVector);
  rotateLeft1(vector, SizeOfVector, 3);
  printVector(vector, SizeOfVector);
  rotateLeft2(vector, SizeOfVector, 3);
  printVector(vector, SizeOfVector);
  rotateLeft3(vector, SizeOfVector, 3);
  printVector(vector, SizeOfVector);
  return 0;
}
