#include <stdio.h>

#define rootIndex 1
#define leftChildIndex(i) (i * 2)
#define rightChildIndex(i) (i * 2 + 1)
#define parentIndex(i) (i / 2)
#define isNullIndex(i, size) (i < 1 || i > size)
#define nodeValue(array, i) (array[i - 1])
void heapSiftup(int* array, int size) {
  int index = size;
  while (1) {
    if (index == rootIndex) {
      break;
    }
    int parent = parentIndex(index);
    int parentValue = nodeValue(array, parent);
    int indexValue = nodeValue(array, index);
    if (parentValue <= indexValue) {
      break;
    }
    nodeValue(array, parent) = indexValue;
    nodeValue(array, index) = parentValue;
    index = parent;
  }
}
void heapSiftdown(int* array, int size) {
  int index = 1;
  while (1) {
    int leftIndex = leftChildIndex(index);
    if (leftIndex > size) {
      break;
    }
    int nextIndex = leftIndex;
    int rightIndex = rightChildIndex(index);
    if (rightIndex <= size) {
      if (nodeValue(array, rightIndex) < nodeValue(array, leftIndex)) {
        nextIndex = rightIndex;
      }
    }
    int indexValue = nodeValue(array, index);
    int nextValue = nodeValue(array, nextIndex);
    if (indexValue <= nextValue) {
      break;
    }
    nodeValue(array, index) = nextValue;
    nodeValue(array, nextIndex) = indexValue;
    index = nextIndex;
  }
}
// Heap: child node >= parent node
void makeArrayHeap(int* array, int size) {
  for (int i = 1; i <= size; i++) {
    heapSiftup(array, i);
  }
}
void makeArrayHeap2(int* array, int size) {
  for (int i = 1; i <= size; i++) {
    heapSiftdown(array + size - i, i);
  }
}
void printArray(int* array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
int main(int argc, char* argv[]) {
  int vector[] = {3, -2, -2, 5, 6, -2, 3, -4, 7, 2, -1, -4, 3, 9, -2, -7, 4};
  printArray(vector, sizeof(vector) / sizeof(int));
  makeArrayHeap(vector, sizeof(vector) / sizeof(int));
  printArray(vector, sizeof(vector) / sizeof(int));
  int vector2[] = {3, -2, -2, 5, 6, -2, 3, -4, 7, 2, -1, -4, 3, 9, -2, -7, 4};
  printArray(vector2, sizeof(vector2) / sizeof(int));
  makeArrayHeap(vector2, sizeof(vector2) / sizeof(int));
  printArray(vector2, sizeof(vector2) / sizeof(int));
  return 0;
}