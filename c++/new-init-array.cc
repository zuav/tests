#include <iostream>


int main()
{
    char *a = new char[3]; //();

    std::cout << "a[0] = " << int(a[0]) << std::endl
              << "a[1] = " << int(a[1]) << std::endl
              << "a[2] = " << int(a[2]) << std::endl;

    return 0;
}
