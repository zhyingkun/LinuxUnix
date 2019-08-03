#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* str1, const void* str2) {
  const char* tmpStr1 = *(const char**)str1;
  const char* tmpStr2 = *(const char**)str2;
  for (int i = 0;; i++) {
    if (tmpStr1[i] == '\0') {
      if (tmpStr2[i] == '\0') {
        return 0;
      }
      return -1;
    }
    if (tmpStr2[i] == '\0') {
      return 1;
    }
    if (tmpStr1[i] > tmpStr2[i]) {
      return 1;
    }
    if (tmpStr1[i] < tmpStr2[i]) {
      return -1;
    }
  }
  return 0;
  // return strcmp(*(char**)str1, *(char**)str2);
}
int commonLength(char* str1, char* str2) {
  int index = 0;
  for (int i = 0;; i++) {
    if (str1[i] == '\0' || str1[i] != str2[i]) {
      break;
    }
    index++;
  }
  //   printf("%d", index);
  return index;
}
void findMaxSubString(char* str, int length) {
  char** strPointer = (char**)malloc(sizeof(char*) * length);
  for (int i = 0; i < length; i++) {
    strPointer[i] = str + i;
  }
  //   for (int i = 0; i < length; i++) {
  //     printf("%s\n", strPointer[i]);
  //   }
  qsort(strPointer, length, sizeof(char*), compare);
  //   for (int i = 0; i < length; i++) {
  //     printf("%s\n", strPointer[i]);
  //   }
  int maxLength = 0;
  int maxIndex = 0;
  int secondLength = 0;
  int secondIndex = 0;
  int thirdLength = 0;
  int thirdIndex = 0;
  for (int i = 0; i < length - 1; i++) {
    int comLen = commonLength(strPointer[i], strPointer[i + 1]);
    if (comLen > maxLength) {
      maxLength = comLen;
      maxIndex = i;
    } else {
      if (comLen > secondLength) {
        secondLength = comLen;
        secondIndex = i;
      } else {
        if (comLen > thirdLength) {
          thirdLength = comLen;
          thirdIndex = i;
        }
      }
    }
  }
  printf("%s\n", str);
  //   printf("%d\n", maxLength);
  printf("%d %.*s\n", maxLength, maxLength, strPointer[maxIndex]);
  printf("%d %.*s\n", secondLength, secondLength, strPointer[secondIndex]);
  printf("%d %.*s\n", thirdLength, thirdLength, strPointer[thirdIndex]);
}
int main(int argc, char* argv[]) {
  char* str = "Ask not what your country can do for you, but what you can do for your country";
  findMaxSubString(str, strlen(str));
}
