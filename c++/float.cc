#include <iostream>
#include <iomanip>

int main()
{
    float f1 = 0;
    float f2 = 1.0;

    std::cout << "default" << std::endl
              << "f1 = " << f1 << std::endl
              << "f2 = " << f2 << std::endl
              << "fixed" << std::endl
              << "f1 = " << std::fixed << f1 << std::endl
              << "f2 = " << std::fixed << f2 << std::endl;

    return 0;
}
