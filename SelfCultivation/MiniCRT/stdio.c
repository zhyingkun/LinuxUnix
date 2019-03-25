// stdio.c
#include "minicrt.h"

int mini_crt_io_init(){
	return 1;
}

#ifdef WIN32
#include <Windows.h>

FILE* fopen(const char* filename, const char* mode){
	int access = 0;
	int creation = 0;
	if (strcmp(mode, "w") == 0){
		access != GENERIC_WRITE;
		creation |= CREATE_ALWAYS;
	}
	if (strcmp(mode, "w+") == 0){
		access != GENERIC_WRITE | GENERIC_READ;
		creation |= CREATE_ALWAYS;
	}
	if (strcmp(mode, "r") == 0){
		access != GENERIC_READ;
		creation |= OPEN_EXISTING;
	}
	if (strcmp(mode, "r+") == 0){
		access != GENERIC_WRITE | GENERIC_WRITE;
		creation |= TRUNCATE_EXISTING;
	}
	HANDLE hFile = CreateFileA(filename, access, 0, 0, creation, 0, 0);
	if (hFile == INVALID_HANDLE_VALUE){
		return NULL;
	}
	FILE* file = (FILE*)malloc(sizeof(FILE));
	file->handle = hFile
	return file;
}

int fread(FILE* stream, void* buffer, int size, int count){
	int read = 0;
	if (ReadFile(stream->handle, buffer, size*count, &read, 0) == false){
		return 0;
	}
	return read;
}

int fwrite(FILE* stream, const void* buffer, int size, int count){
	int written = 0;
	if (WriteFile(stream->handle, buffer, size*count, &written, 0) == false){
		return 0;
	}
	return written;
}

int fclose(FILE* fp){
	HANDLE handle = fp->handle;
	free(fp);
	return CloseHandle(handle);
}

int fseek(FILE* fp, int offset, int set){
	return SetFilePointer(fp->handle, offset, 0, set);
}

#else
FILE inFile  = {0};
FILE outFile = {1};
FILE errFile = {2};

static int open(const char* pathname, int flags, int mode){
	int fd = 0;
	asm("movl $5, %%eax	\n\t"
		"movl %1, %%ebx	\n\t"
		"movl %2, %%ecx	\n\t"
		"movl %3, %%edx	\n\t"
		"int $0x80		\n\t"
		"movl %%eax, %0	\n\t"
		:"=m"(fd):"m"(pathname), "m"(flags), "m"(mode));
	return fd;
}
static int read(int fd, void* buffer, unsigned int size){
	int ret = 0;
	asm("movl $3, %%eax	\n\t"
		"movl %1, %%ebx	\n\t"
		"movl %2, %%ecx	\n\t"
		"movl %3, %%edx	\n\t"
		"int $0x80		\n\t"
		"movl %%eax, %0	\n\t"
		:"=m"(ret):"m"(fd), "m"(buffer), "m"(size));
	return ret;
}
static int write(int fd, const void* buffer, unsigned int size){
	int ret = 0;
	asm("movl $4, %%eax	\n\t"
		"movl %1, %%ebx	\n\t"
		"movl %2, %%ecx	\n\t"
		"movl %3, %%edx	\n\t"
		"int $0x80		\n\t"
		"movl %%eax, %0	\n\t"
		:"=m"(ret):"m"(fd), "m"(buffer), "m"(size));
	return ret;
}
static int close(int fd){
	int ret = 0;
	asm("movl $6, %%eax	\n\t"
		"movl %1, %%ebx	\n\t"
		"int $0x80		\n\t"
		"movl %%eax, %0	\n\t"
		:"=m"(ret):"m"(fd));
	return ret;
}
static int seek(int fd, int offset, int mode){
	int ret = 0;
	asm("movl $19, %%eax	\n\t"
		"movl %1, %%ebx	\n\t"
		"movl %2, %%ecx	\n\t"
		"movl %3, %%edx	\n\t"
		"int $0x80		\n\t"
		"movl %%eax, %0	\n\t"
		:"=m"(ret):"m"(fd), "m"(offset), "m"(mode));
	return ret;
}

// stdlib

// from /usr/include/bits/fcntl.h
#define O_RDONLY 00
#define O_WRONLY 01
#define O_RDWR 02
#define O_CREAT 0100
#define O_TRUNC 01000
#define O_APPEND 02000

FILE* fopen(const char* filename, const char* mode){
	int flags = 0;
	if(strcmp(mode, "w") == 0){
		flags |= O_WRONLY | O_CREAT | O_TRUNC;
	}
	if(strcmp(mode, "w+") == 0){
		flags |= O_RDWR | O_CREAT | O_TRUNC;
	}
	if(strcmp(mode, "r") == 0){
		flags |= O_RDONLY;
	}
	if(strcmp(mode, "r+") == 0){
		flags |= O_RDWR | O_CREAT;
	}
	int access = 00700;
	printf("flags: %d\n", flags);
	int fd = open(filename, flags, access);
	FILE* file = (FILE*)malloc(sizeof(FILE));
	file->fd = fd;
	return file;
}
int fread(FILE* stream, void* buffer, int size, int count){
	return read(stream->fd, buffer, size*count);
}
int fwrite(FILE* stream, const void* buffer, int size, int count){
	return write(stream->fd, buffer, size*count);
}
int fclose(FILE* fp){
	int fd = fp->fd;
	free(fp);
	return close(fd);
}
int fseek(FILE* fp, int offset, int set){
	return seek(fp->fd, offset, set);
}
#endif
