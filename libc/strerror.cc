#include <string.h>
#include <iostream>

int main(int argc, char *argv[])
{
    int errcode = strtol(argv[1], 0, 0);
    std::cout << errcode << ": " << strerror(errcode) << std::endl;

    return 0;
}
