#include <string.h>


int main()
{
    const char *haystack = "haystack-with-needle";
    const char *needle   = "needle";

    if (strstr(haystack, needle) == 0)
        return 1;

    if (memmem(haystack, strlen(haystack), needle, strlen(needle)) == 0)
        return 2;

    return 0;
}
