#include <stdarg.h>
#include <stdio.h>

struct Foo {
    Foo(const char *fmt, ...);
};


Foo::Foo(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

int main()
{
    Foo f("arg %d; arg %s\n", 1, "two");

    return 0;
}
