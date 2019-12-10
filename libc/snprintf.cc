#include <stdarg.h>
#include <stdio.h>
#include <iostream>

void print_warning(const char *format, ...);

int main()
{
    print_warning("%s not found (setting entry to inactive) : %s", "Route Group", "Utah801");

    return 0;
}

void print_warning(const char *format, ...)
{
    const char *filename = "file.txt";
    int curline = 2;
    char buf[128];

    snprintf(buf, sizeof(buf), "Warning: %s (%d) : %s", filename, curline, format);

    va_list args;
    va_start (args, format);
    char buf2[128];
    vsnprintf(buf2, sizeof(buf2), buf, args);

    std::cout << buf2 << std::endl;
}
