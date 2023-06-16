#include <stdint.h>
#include <iostream>


int main(int argc, char *argv[])
{
    char buf1[] = "123";
    uint8_t buf2[] = "123";

    std::cout << "sizeof(buf1): " << sizeof(buf1) << std::endl
              << "sizeof(buf2): " << sizeof(buf2) << std::endl;

    return 0;
}
