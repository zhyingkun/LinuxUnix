extern int __attribute__((__cdecl__)) func1(int a, int b, int c, int d);
extern int __attribute__((__stdcall__)) func2(int a, int b, int c, int d);
extern int __attribute__((__fastcall__)) func3(int a, int b, int c, int d);

int main(){
	int a=func1(1, 2, 3, 4);
	int b=func2(1, 2, 3, 4);
	int c=func3(1, 2, 3, 4);
	return a+b+c;
}
