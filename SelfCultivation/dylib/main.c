#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

extern int gDefInExe;
int gDefInExe = 1;

extern int gDefInB;
extern int gDefInA;

int funcDefInA();
int funcDefInB();
int getValueFromC(int val);

extern int funcDefInExe(){
	printf("In funcDefInExe\n");
	return 1;
}

int main(int argc, char* argv[])
{
	if(argc != 2){
		fprintf(stderr, "usage: main load/unload\n");
		fflush(NULL);
		return -1;
	}
	printf("Before Call funcDefInA\n");
	int a = funcDefInA();
	printf("After Call funcDefInA, a: %d\n", a);
	printf("Before Call funcDefInB\n");
	void* handleB = NULL;
	int b = funcDefInB();
	printf("After Call funcDefInB, b: %d\n", b);
	int ret = funcDefInExe() + gDefInExe + gDefInA + gDefInB;
	
	if(strcmp(argv[1], "load") == 0){
		printf("Load libcc.so now!\n");
		handleB = dlopen("libcc.so", RTLD_LAZY | RTLD_GLOBAL);
		//handleB = dlopen("libcc.so", RTLD_LAZY | RTLD_LOCAL);
		if(handleB == NULL){
			fprintf(stderr, "error: dlopen libcc.so failed\n");
			fflush(NULL);
			return -1;
		}
		int (*funcGetValueFromC)(int) = dlsym(handleB, "getValueFromC");
		if(funcGetValueFromC != NULL){
			int valC = funcGetValueFromC(13);
			printf("Value from libcc.so: %d, right is 31\n", valC);
		}
	}
	int valC = getValueFromC(12);
	printf("Value from C: %d, right is 29\n", valC);
	if(strcmp(argv[1], "load") == 0){
		dlclose(handleB);
	}
	return ret;
}
