int main(){
	int argc;
	char** argv;
	char* ebp_reg = 0;
	asm("movq %%rbp, %0 \n":"=r"(ebp_reg));
	argc = *(int*)(ebp_reg + 8);
	argv = (char**)(ebp_reg + 16);

	// exit
	int exitCode;
	asm("mov $60, %%eax \n\t"
		"mov %0,  %%edi \n\t"
		"syscall		\n\t"
		"hlt			\n\t"::"m"(exitCode));

	// brk
	void* ret, *end_data_segment;
	// brk system call number: 12
	// CentOS 7.5 in /usr/include/asm/unistd_64.h:
	// #define __NR_brk 12
	asm("mov $12, %%eax	\n\t"
		"mov %1,  %%rdi	\n\t"
		"syscall			\n\t"
		"movq %%rax, %0		\n\t"
		:"=r"(ret):"m"(end_data_segment));

	// open
	int fd, flags, mode;
	char* pathname;
	asm("mov $2,  %%eax	\n\t"
		"movq %1,  %%rdi	\n\t"
		"mov %2,  %%esi	\n\t"
		"mov %3,  %%edx	\n\t"
		"syscall			\n\t"
		"mov %%eax, %0		\n\t"
		:"=m"(fd):"m"(pathname), "m"(flags), "m"(mode));

	// read
	void* buffer;
	int size;
	asm("mov $0,  %%eax	\n\t"
		"mov %1,  %%edi	\n\t"
		"movq %2,  %%rsi	\n\t"
		"mov %3,  %%edx	\n\t"
		"syscall			\n\t"
		"mov %%eax, %0		\n\t"
		:"=m"(ret):"m"(fd), "m"(buffer), "m"(size));

	// write
	asm("mov $1,  %%eax	\n\t"
		"mov %1,  %%edi	\n\t"
		"movq %2,  %%rsi	\n\t"
		"mov %3,  %%edx	\n\t"
		"syscall			\n\t"
		"mov %%eax, %0		\n\t"
		:"=m"(ret):"m"(fd), "m"(buffer), "m"(size));

	// close
	asm("mov $3,  %%eax	\n\t"
		"mov %1,  %%edi	\n\t"
		"syscall			\n\t"
		"mov %%eax, %0		\n\t"
		:"=m"(ret):"m"(fd));

	// seek
	int offset;
	asm("mov $8,  %%eax	\n\t"
		"mov %1,  %%edi	\n\t"
		"mov %2,  %%esi	\n\t"
		"mov %3,  %%edx	\n\t"
		"syscall			\n\t"
		"mov %%eax, %0		\n\t"
		:"=m"(ret):"m"(fd), "m"(offset), "m"(mode));
}
