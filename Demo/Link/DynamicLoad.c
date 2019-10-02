#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <dlfcn.h>

int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];

typedef void (*AddVecProc)(int *, int *, int *, int);

int main(int argc, char const *argv[])
{
    void *handler = dlopen("libvector.so", RTLD_LAZY);
    if (!handler)
    {
        fprintf(stderr, "%s\n", dlerror());
        return -1;
    }
    AddVecProc addvec = dlsym(handler, "addvec");
    char *error = dlerror();
    if (error != NULL)
    {
        fprintf(stderr, "%s\n", error);
        return -1;
    }
    addvec(x, y, z, 2);
    printf("z = [%d, %d]\n", z[0], z[1]);
    int loopCount = 0;
//    for (;;)
//    {
//        sleep(1);
//        printf("Count: %d\n", loopCount++);
//    }
    if (dlclose(handler) < 0)
    {
        fprintf(stderr, "%s\n", dlerror());
        return -1;
    }
    return 0;
}
