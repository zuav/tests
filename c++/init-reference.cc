#include <iostream>


int main(int, char *[])
{
    int i = 5;
    int& r1 = i;
    int& r2 = r1;

    std::cout << "i  = " << i << std::endl
              << "r1 = " << r1 << std::endl
              << "r2 = " << r1 << std::endl;

    r2 = 6;

    std::cout << "i  = " << i << std::endl
              << "r1 = " << r1 << std::endl
              << "r2 = " << r1 << std::endl;

    return 0;
}
