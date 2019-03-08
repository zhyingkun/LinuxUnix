char* str = "Hello World\n";

void print(){
	asm(	"movl $13, %%edx \n\t"
		"movl %0, %%ecx \n\t"
		"movl $2,  %%ebx \n\t"
		"movl $4,  %%eax \n\t"
		"int  $0x80      \n\t"
		::"r"(str):"edx","ecx","ebx","eax");
}

void exit(){
	asm(	"movl $42, %ebx \n\t"
		"movl $1,  %eax \n\t"
		"int $0x80      \n\t");
}

void nomain()
{
	print();
	exit();
}
