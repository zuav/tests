#include <iostream>


int main(int, char *[])
{
    int *pi1 = new int;
    int *pi2 = new int();

    std::cout << "*pi1 = " << *pi1 << std::endl
              << "*pi2 = " << *pi2 << std::endl;

    return 0;
}
