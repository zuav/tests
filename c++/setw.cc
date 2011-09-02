#include <iostream>
#include <iomanip>

int main()
{
    unsigned long d = 5;
    unsigned long m = 8;
    unsigned long y = 1965;

    std::cout << std::setw(2) << std::setfill('0') << d << '.'
              << std::setw(2) << std::setfill('0') << m << '.'
              << y << std::endl;

    return 0;
}
