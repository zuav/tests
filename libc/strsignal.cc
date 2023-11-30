#include <string.h>
#include <iostream>


int main()
{
    int signum = 15;

    std::cout << signum << ": " << strsignal(signum) << std::endl;

    return 0;
}
