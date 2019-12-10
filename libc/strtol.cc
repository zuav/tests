#include <stdlib.h>
#include <iostream>


int main(int argc, char *argv[])
{
    long v1 = strtol(argv[1], 0, 10);
    long v2 = strtol(argv[2], 0, 10);
    std::cout << "argv[1] = " << v1 << '\n'
              << "argv[2] = " << v2 << '\n';

    return 0;
}
