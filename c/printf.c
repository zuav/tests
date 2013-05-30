#include <stdio.h>

int main()
{
    printf("%f\n", 123.456789);
    printf("%Lf\n", 123.4567890123L);
    printf("%a\n", 123.456789);
    printf("%%a  123.4567890123:  %a\n", 123.4567890123);
    printf("\n");
    printf("%a\n", -123.4567890123);
    printf("%a\n", 123.456);
    printf("%%La 123.4567890123L: %La\n", 123.4567890123L);

    char *ptr;
    printf("ptr: %p\n", (void *)ptr);
    ptr = &ptr;
    printf("ptr: %p\n", (void *)ptr);

    return 0;
}
