#include <stdlib.h>
#include <iostream>

int main(int argc, char *argv[])
{
    int a = strtol(argv[1], 0, 0);
    int b = strtol(argv[2], 0, 0);
    std::cout << a << " modulo " << b << " = " << (a % b) << std::endl;

    return 0;
}
