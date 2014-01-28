#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define MSG_SIZE  2048


void f(const char *fmt, ...)
{
    char message[MSG_SIZE];

    va_list args;
    va_start(args, fmt);
    vsnprintf(message, MSG_SIZE, fmt, args);
    va_end(args);

    printf("%s%s%s\n", (message[0] ? message : ""), (message[0] ? ": " : ""), "tail");
}

int main()
{
    f("");
    f("no args");
    f("one %s arg", "string");

    return 0;
}
