#include "minicrt.h"

typedef struct _func_node {
	atexit_func_t func;
	void* arg;
	int is_cxa;
	struct _func_node* next;
} func_node;

static func_node* atexit_list = 0;

int register_atexit(atexit_func_t func, void* arg, int is_cxa){
	if (func == NULL){
		return -1;
	}
	func_node* node = (func_node*)malloc(sizeof(func_node));
	if (node == NULL){
		return -1;
	} 
	node->func = func;
	node->arg = arg;
	node->is_cxa = is_cxa;
	node->next = atexit_list;
	atexit_list = node;
	return 0;
}

#ifdef WIN32
#else
typedef void (*cxa_func_t)();
int __cxa_atexit(cxa_func_t func, void* arg, void* unused){
	return register_atexit((atexit_func_t)func, arg, 1);
}
#endif

int atexit(atexit_func_t func){
	return register_atexit(func, NULL, 0);
}

void mini_crt_call_exit_routine(){
	func_node* p = atexit_list;
	for(; p != NULL; p = p->next){
#ifdef WIN32
		p->func();
#else
		if (p->is_cxa){
			((cxa_func_t)p->func)(p->arg);
		}else{
			p->func();
		}
#endif
		free(p);
	}
	atexit_list = NULL;
}
