#include <stdio.h>

int main()
{
    printf("%f\n", 123.456789);
    printf("%Lf\n", 123.4567890123L);
    printf("%a\n", 123.456789);
    printf("%a\n", 123.4567890123);
    printf("\n");
    printf("%a\n", -123.4567890123);
    printf("%a\n", 123.456);
    printf("%La\n", 123.4567890123L);

    return 0;
}
