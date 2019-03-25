#include "minicrt.h"

int fputc(FILE* stream, int c){
	if (fwrite(stream, &c, 1, 1) != 1){
		return EOF;
	}
	return c;
}
int fputs(FILE* stream, const char* str){
	int len = strlen(str);
	if (fwrite(stream, str, 1, len) != len){
		return EOF;
	}
	return len;
}

#ifdef WIN32
#include <Windows.h>
#else
#define va_list char*
#define va_start(ap,arg) (ap=(va_list)&arg+sizeof(arg))
#define va_arg(ap,t) (*(t*)((ap+=sizeof(t))-sizeof(t)))
#define va_end(ap) (ap=(va_list)0)
#endif

int vfprintf(FILE* stream, const char* format, va_list arglist){
	int translating = 0;
	int ret = 0;
	const char* p = 0;
	for(p = format; *p != '\0'; p++){
		switch(*p){
		case '%':
			if (translating == 0){
				translating = 1;
			}else{
				if (fputc(stream, '%') < 0){
					return EOF;
				}
				ret++;
				translating = 0;
			}
			break;
		case 'd':
			if (translating == 0){
				if (fputc(stream, 'd') < 0){
					return EOF;
				}
				ret++;
			}else{
				char buf[16];
				translating = 0;
				itoa(va_arg(arglist, int), buf, 10);
				if (fputs(stream, buf) < 0){
					return EOF;
				}
				ret += strlen(buf);
			}
			break;
		case 's':
			if (translating == 0){
				if (fputc(stream, 's') < 0){
					return EOF;
				}
				ret++;
			}else{
				const char* str = va_arg(arglist, const char*);
				translating = 0;
				if (fputs(stream, str) < 0){
					return EOF;
				}
				ret += strlen(str);
			}
			break;
		default:
			if (translating != 0){
				translating = 0;
			}
			if (fputc(stream, *p) < 0){
				return EOF;
			}
			ret++;
			break;
		}
	}
	return ret;
}

int printf(const char* format, ...){
	va_list(arglist);
	va_start(arglist, format);
	return vfprintf(stdout, format, arglist);
}

int fprintf(FILE* stream, const char* format, ...){
	va_list(arglist);
	va_start(arglist, format);
	return vfprintf(stream, format, arglist);	
}
