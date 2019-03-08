#include <stdio.h>
#include <stdlib.h>

// Test for loop
int forLoop(int n){
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += i + 1;
	}
	return sum;
}

// Test do while loop
int doWhileLoop(int n){
	int sum = 0;
	do{
		sum += 1;
	} while (sum < n);
	return sum;
}

// Test while loop
int whileLoop(int n){
	int sum = 0;
	while (sum < n){
		sum += 2;
	}
	return sum;
}

// Test break and continue
int breakContinue(int n){
	int sum = 0;
	int i;
	for (i = 0; i < n; i++){
		if (i > 5){
			sum += 1;
			continue;
		}
		if (i > 8){
			sum += 3;
			break;
		}
		sum += 2;
	}
	return sum;
}

// Test if else goto
int ifElseGoto(){
	int sum = 0;
start:
	if (sum < 10){
		sum += 1;
		goto start;
	}else{
		sum += 2;
	}
	return sum;
}

// Test switch case default
int switchCaseDefault(int n){
	int sum = 0;
	int i;
	switch (n){
	case 0:
		sum += 1;
		break;
	case 1:
		sum += 2;
		break;
	default:
		sum += 6;
		break;
	}
	switch (n){
	case 0:
		sum *= 2;
		break;
	case 1:
		sum *= 4;
		break;
	case 2:
		sum *= 3;
		break;
	case 3:
		sum *= 2;
		break;
	default:
		sum += 6;
		break;
	}
	return sum;
}

// Test function call
int functionCall(int a, char b, char *c, int d, int e, int f, int g){
	printf("char b: %c\n", b);
	printf("char*c: %s\n", c);
	return a + d + e + f + g;
}

// Varilable Scope
int GlobalVarInited = 10;
int GlobalVarNotInit;

// Global struct
struct StructType
{
	int index;
	char buf[3];
	char *name;
};
void displayStruct(struct StructType StructVar){
	printf("index: %d\n", StructVar.index);
	printf("buf: %c, %c, %c\n", StructVar.buf[0], StructVar.buf[1], StructVar.buf[2]);
	printf("*name: %s\n", StructVar.name);
}
struct StructType GlobalStructVar = {.index = 1, .buf = {'x', 'y', 'z'}, .name = "GlobalStructVar"};

int main(){
	int LocalVar;
	char *StrPtr = "HelloWorld";
	char CharArray[] = "abcd";
	static int LocalStaticVar;
	char *NewPtr = (char *)malloc(10);
	struct StructType LocalStructVar = {.index = 2, .buf = {'u', 'v', 'w'}, .name = "LocalStructVar"};
	printf("GlobalVarInited: %d\n", GlobalVarInited);
	printf("GlobalVarNotInit: %d\n", GlobalVarNotInit);
	printf("LocalVar: %d\n", LocalVar);
	printf("LocalStaticVar: %d\n", LocalStaticVar);
	printf("StrPtr: %s\n", StrPtr);
	printf("CharArray: %s\n", CharArray);
	printf("NewPtr[0]: %c\n", NewPtr[0]);
	displayStruct(GlobalStructVar);
	displayStruct(LocalStructVar);
	int result = forLoop(3);
	printf("forloop: %d\n", result);
	result = doWhileLoop(3);
	printf("dowhileloop: %d\n", result);
	result = whileLoop(3);
	printf("whileloop: %d\n", result);
	result = breakContinue(10);
	printf("breakcontinue: %d\n", result);
	result = ifElseGoto();
	printf("ifelsegoto: %d\n", result);
	result = switchCaseDefault(10);
	printf("switchcasedefault: %d\n", result);
	result = functionCall(1, 'b', "ccc", 2, 3, 4, 5);
	printf("functioncall: %d\n", result);

	return 0;
}
