#include <stdio.h>

#if defined(__i386)
#pragma pack(1)
int i386_defined = 1;
#else
//#error __i386 is not define!
int i386_defined = 0;
#endif


int main()
{
    printf("__i386 defined: %d\n", i386_defined);

    return 0;
}
