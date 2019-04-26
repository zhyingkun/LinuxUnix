#include <stdio.h>
#include <dlfcn.h>

typedef void (*tmpFunc)();
void GetHelloStr()
{
  printf("Hello\n");
}

int main(int argc, char *argv[]) {
  void* handler = dlopen(NULL, RTLD_NOW | RTLD_GLOBAL);
  printf("handler: %x\n", handler);
  tmpFunc func = (tmpFunc)dlsym(handler, "GetHelloStr");
  printf("Ponter: %x\n", func);
  if(func != NULL){
    func();
  }
  return 0;
}
