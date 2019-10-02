#include <stdio.h>

int bitmode_main(int argc, char* argv[]) {
  printf("__FILE__:%s, __LINE__:%d\n", __FILE__, __LINE__);
  float fValue = -0.0;
  int iValue = 0;
  // unsigned char byte[sizeof(float)];
  // *(float*)byte = fValue;
  int i;
  for (i = 0; i < sizeof(float); i++) {
    printf("fValue byte[%d]=%u\n", i, ((unsigned char*)&fValue)[i]);
  }
  printf("Hex Value: %x\n", *(int*)&fValue);
  return 0;
}
