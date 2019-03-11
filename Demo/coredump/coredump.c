#include <stdio.h>
void func1()
{
	printf("In function func1");
}
int main()
{
	printf("Core dump test");
	func1();
	int a;
	scanf("%d", &a);
	return a;
}
