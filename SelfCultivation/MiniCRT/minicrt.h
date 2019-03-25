#ifndef __MINI_CRT_H__
#define __MINI_CRT_H__
#ifdef __cplusplus
extern "C" {
#endif

// malloc
#ifndef NULL
#define NULL (0)
#endif
void free(void* ptr);
void* malloc(unsigned int size);
static void* brk(void* end_data_segment);
int mini_crt_heap_init();

// string
char* itoa(int n, char* str, int radix);
int strcmp(const char* str, const char* dst);
char* strcpy(char* dest, const char* src);
unsigned int strlen(const char* str);

// file and IO
#define EOF (-1)
#ifdef WIN32
typedef int FILE;
#define stdin ((FILE*)(GetStdHandle(STD_INPUT_HANDLE)))
#define stdout ((FILE*)(GetStdHandle(STD_OUTPUT_HANDLE)))
#define stderr ((FILE*)(GetStdHandle(STD_ERROR_HANDLE)))
#else
typedef struct FILE {
	int fd;
} FILE;
extern FILE inFile;
extern FILE outFile;
extern FILE errFile;
#define stdin  (&inFile)
#define stdout (&outFile)
#define stderr (&errFile)
#endif
int mini_crt_io_init();
FILE* fopen(const char* filename, const char* mode);
int fread(FILE* stream, void* buffer, int size, int count);
int fwrite(FILE* stream, const void* buffer, int size, int count);
int fclose(FILE* fp);
int fseek(FILE* fp, int offset, int set);

// printf
int fputc(FILE* stream, int c);
int fputs(FILE* stream, const char* str);
int printf(const char* format, ...);
int fprintf(FILE* stream, const char* format, ...);

// internal
void do_global_ctors();
void mini_crt_call_exit_routine();

// atexit
typedef void (*atexit_func_t)();
int atexit(atexit_func_t func);

#ifdef __cplusplus
}
#endif
#endif
