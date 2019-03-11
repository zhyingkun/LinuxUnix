#include <stdio.h>

int getInt(){
	return 42;
}
int gInt = 43;
int* getIntAddr(){
	return &gInt;
}

int main(int argc, char* argv[]){
	int octal = 012;
	int a = 1, b = 2;
	// int c = a+++++b;
	int c = a+++b;
	printf("octal: %d\na: %d\nb: %d\nc: %d\n", octal, a, b, c);
	// printf("getInt: %d\n", getInt()++);
	printf("getInt: %d\n", (*getIntAddr())++);

	char* comment = /*/**/"*/"/*"/**/;
	int comInt = /*/*/0*/**/1;
	printf("Test NestComment: %s %d\n", comment, comInt);
	return 0;
}
