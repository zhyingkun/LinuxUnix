#include <stdio.h>
#include <stdlib.h>

int findMaxSumOfContinuousSubVector1(int* vector, int size) {
  int maxSum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {
        sum += vector[k];
      }
      if (sum > maxSum) {
        maxSum = sum;
      }
    }
  }
  return maxSum;
}
int findMaxSumOfContinuousSubVector2(int* vector, int size) {
  int maxSum = 0;
  for (int i = 0; i < size; i++) {
    int sum = 0;
    for (int j = i; j < size; j++) {
      sum += vector[j];
      if (sum > maxSum) {
        maxSum = sum;
      }
    }
  }
  return maxSum;
}
int findMaxSumOfContinuousSubVector3(int* vector, int size) {
  int* sumVector = (int*)malloc(sizeof(int) * size);
  sumVector[0] = vector[0];
  for (int i = 1; i < size; i++) {
    sumVector[i] = sumVector[i - 1] + vector[i];
  }
  int maxSum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      int sum = 0;
      if (i == 0) {
        sum = sumVector[j];
      } else {
        sum = sumVector[j] - sumVector[i - 1];
      }
      if (sum > maxSum) {
        maxSum = sum;
      }
    }
  }
  free(sumVector);
  return maxSum;
}
int RecursiveFindSum(int* vector, int left, int right) {
  if (left > right) {
    return 0;
  }
  if (left == right) {
    return 0 > vector[left] ? 0 : vector[left];
  }
  int middle = (left + right) / 2;
  int leftMax = 0;
  int sum = 0;
  for (int i = middle; i >= left; i--) {
    sum += vector[i];
    if (sum > leftMax) {
      leftMax = sum;
    }
  }
  int rightMax = 0;
  sum = 0;
  for (int i = middle + 1; i <= right; i++) {
    sum += vector[i];
    if (sum > rightMax) {
      rightMax = sum;
    }
  }
  int mainMax = leftMax + rightMax;
  leftMax = RecursiveFindSum(vector, left, middle);
  rightMax = RecursiveFindSum(vector, middle + 1, right);
  if (leftMax > mainMax) {
    mainMax = leftMax;
  }
  if (rightMax > mainMax) {
    mainMax = rightMax;
  }
  return mainMax;
}
int findMaxSumOfContinuousSubVector4(int* vector, int size) {
  return RecursiveFindSum(vector, 0, size - 1);
}
int findMaxSumOfContinuousSubVector5(int* vector, int size) {
  int mainMax = 0;
  int sum = 0;
  for (int i = 0; i < size; i++) {
    int tmpSum = sum + vector[i];
    if (tmpSum > 0) {
      sum = tmpSum;
    } else {
      sum = 0;
    }
    if (sum > mainMax) {
      mainMax = sum;
    }
  }
  return mainMax;
}
int main(int argc, char* argv[]) {
  int vector[] = {3, -2, -2, 5, 6, -2, 3, -4, 7, 2, -1, -4, 3, 9, -2, -7, 4}; // 24
  int sum1 = findMaxSumOfContinuousSubVector1(vector, sizeof(vector) / sizeof(int));
  int sum2 = findMaxSumOfContinuousSubVector2(vector, sizeof(vector) / sizeof(int));
  int sum3 = findMaxSumOfContinuousSubVector3(vector, sizeof(vector) / sizeof(int));
  int sum4 = findMaxSumOfContinuousSubVector4(vector, sizeof(vector) / sizeof(int));
  int sum5 = findMaxSumOfContinuousSubVector5(vector, sizeof(vector) / sizeof(int));
  printf("Max Sum of Continuous Sub Vector: %d %d %d %d %d\n", sum1, sum2, sum3, sum4, sum5);
  return 0;
}
