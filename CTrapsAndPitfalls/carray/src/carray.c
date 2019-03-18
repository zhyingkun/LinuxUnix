#include <stdio.h>

int main(int argc, char* argv[]){
	int myArray[8];
	for(int i=0; i<8; i++){
		myArray[i] = 0;
	}
	myArray[0] = 1;
	*(myArray + 1) = 2;
	2[myArray] = 3;

	//int (*pArray)[8];
	//pArray = &myArray;
	int* pArray;
	pArray = myArray;
	pArray[3] = 4;
	*(pArray + 4) = 5;
	5[pArray] = 6;

	for(int i=0; i<8; i++){
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}
}
