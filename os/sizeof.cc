#include <time.h>
#include <iostream>
#include <stdint.h>


struct Uint_128 {
    uint64_t hi;
    uint64_t lo;
};



int main()
{
    std::cout << "sizeof(char)              = " << sizeof(char)              << std::endl
              << "sizeof(bool)              = " << sizeof(bool)              << std::endl
              << "sizeof(short)             = " << sizeof(short)             << std::endl
              << "sizeof(int)               = " << sizeof(int)               << std::endl
              << "sizeof(long)              = " << sizeof(long)              << std::endl
              << "sizeof(long long)         = " << sizeof(long long)         << std::endl
              << "sizeof(void *)            = " << sizeof(void *)            << std::endl
              << "sizeof(time_t)            = " << sizeof(time_t)            << std::endl
              << "sizeof(streampos)         = " << sizeof(std::streampos)    << std::endl
              << "sizeof(size_t)            = " << sizeof(size_t)            << std::endl
              << "sizeof(float)             = " << sizeof(float)             << std::endl
              << "sizeof(double)            = " << sizeof(double)            << std::endl
              << "sizeof(long double)       = " << sizeof(long double)       << std::endl
              << "sizeof(unsigned __int128) = " << sizeof(unsigned __int128) << std::endl
              << "sizeof(Uint_128)          = " << sizeof(Uint_128)          << std::endl;

    return 0;
}
