#include <stdarg.h>
#include <stdio.h>

[[gnu::format(printf, 2, 3)]]
static void print(const char *prefix, const char *fmt, ...)  ;

int main()
{
    long v = 15;

    print("test", "v: %d\n", v);

    return 0;
}


void print(const char *prefix, const char *fmt, ...)
{
    printf("%s", prefix);

    va_list arglist;
    va_start(arglist, fmt);

    vprintf(fmt, arglist);

    va_end(arglist);
}
