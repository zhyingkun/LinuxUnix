// #undef NDEBUG // Turn on the assert function, gcc should have -g option
// #define NDEBUG // Turn off the assert function
#include <assert.h>

int main(int argc, char const *argv[])
{
    int x = 12;
    assert(x < 15);
    assert(x > 12);
    return 0;
}
