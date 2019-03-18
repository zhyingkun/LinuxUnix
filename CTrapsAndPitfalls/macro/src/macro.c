#include <stdio.h>

#define f(x) (3*x)

int main(int argc, char* argv[]){
	printf("f(3) = %d\n", f(3));
	printf("f (3) = %d\n", f (3));
	return 0;
}
