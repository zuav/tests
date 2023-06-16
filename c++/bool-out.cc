#include <iostream>

int main()
{
    bool t = true;
    bool f = false;

    std::cout << "t = " << t << std::endl
              << "f = " << f << std::endl
              << std::boolalpha
              << "t = " << t << std::endl
              << "f = " << f << std::endl;

    return 0;
}
