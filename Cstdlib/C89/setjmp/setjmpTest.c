#include <setjmp.h>

static jmp_buf gJmpBuffer;

void fireLongJmp(){
	longjmp(gJmpBuffer, 1);
}

int main(int argc, char* argv[]){
	int ret = 0;
	switch (setjmp(gJmpBuffer)){
		case 0:
			// first setjmp return
			ret += 1;
			fireLongJmp();
			break;
		default:
			// the second setjmp return
			ret += 2;
			break;
	}
	return ret;
}