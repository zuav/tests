#include <endian.h>
#include <iostream>

#ifndef __BYTE_ORDER
#error __BYTE_ORDER is undefined!
#endif

#if __BYTE_ORDER == __BIG_ENDIAN
const char *byte_order = "big endian";
#elif __BYTE_ORDER == __LITTLE_ENDIAN
const char *byte_order = "little endian";
#else
const char *byte_order = "unknown byte order";
#endif


int main()
{
    std::cout << byte_order << std::endl;

    return 0;
}
