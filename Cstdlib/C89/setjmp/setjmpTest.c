#include <setjmp.h>
int printf(const char* format, ...);

static jmp_buf gJmpBuffer;

void fireLongJmpOne(){
	printf("In fireLongJmpOne\n");
	longjmp(gJmpBuffer, 1);
}
void fireLongJmpTwo(){
	printf("In fireLongJmpTwo\n");
	longjmp(gJmpBuffer, 2);
}

int main(int argc, char* argv[]){
	printf("Start...\n");
	switch (setjmp(gJmpBuffer)){
		case 0:
			// first setjmp return
			printf("The 0 case of switch\n");
			fireLongJmpOne();
			break;
		case 1:
			// the second setjmp return
			printf("The 1 case of switch\n");
			fireLongJmpTwo();
			break;
		case 2:
			printf("The 2 case of switch\n");
			break;
		default:
			printf("The default case of switch\n");
			break;
	}
	printf("End.\n");
	return 0;
}