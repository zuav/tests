#include <sys/auxv.h>
#include <unistd.h>
#include <iostream>

int main()
{
    unsigned long pz = getauxval(AT_PAGESZ);
    std::cout << "AT_PAGESZ = " << pz << std::endl;

    pid_t pid = getpid();
    

    return 0;
}
