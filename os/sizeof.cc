#include <time.h>
#include <iostream>

int main()
{
    std::cout << "sizeof(char)      = " << sizeof(char)           << std::endl
              << "sizeof(short)     = " << sizeof(short)          << std::endl
              << "sizeof(int)       = " << sizeof(int)            << std::endl
              << "sizeof(long)      = " << sizeof(long)           << std::endl
              << "sizeof(long long) = " << sizeof(long long)      << std::endl
              << "sizeof(void *)    = " << sizeof(void *)         << std::endl
              << "sizeof(time_t)    = " << sizeof(time_t)         << std::endl
              << "sizeof(streampos) = " << sizeof(std::streampos) << std::endl
              << "sizeof(size_t)    = " << sizeof(size_t)         << std::endl;

    return 0;
}
