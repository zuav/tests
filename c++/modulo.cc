#include <stdlib.h>
#include <iostream>

int main(int argc, char *argv[])
{
    int a = strtol(argv[1], 0, 0);
    int b = strtol(argv[2], 0, 0);
    std::cout << a << " % " << b << " = " << (a % b) << std::endl;

    for (int i=0; i<150; ++i)
        if ((i % 10) == 0)
            std::cout << "i = " << i << std::endl;

    return 0;
}
