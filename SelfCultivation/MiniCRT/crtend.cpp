// crtend.c

#ifdef WIN32
#else
typedef void (*ctor_func)();
ctor_func crt_end[1] __attribute__((section(".ctors"))) = {
	(ctor_func)-1
};
#endif
