#include <stdio.h>

int main(int argc, char* argv[])
{
	float fValue = -0.0;
	int iValue = 0;
	// unsigned char byte[sizeof(float)];
	// *(float*)byte = fValue;
	int i;
	for(i=0; i<sizeof(float); i++){
		printf("fValue byte[%d]=%u\n", i, ((unsigned char*)&fValue)[i]);
	}
	printf("Hex Value: %x\n", *(int*)&fValue);
	return 0;
}
