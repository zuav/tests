#include <string>
#include <iostream>


int main()
{
    std::string s;
    const char *p = s.c_str();

    if (p == "")
        std::cout << "normal empty string: " << p[0] << '\n';
    else
        std::cout << "strange empty string: " << p[0] << '\n';

    return 0;
}
