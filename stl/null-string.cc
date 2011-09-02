#include <string>
#include <iostream>

int main()
{
    const char *p = 0;
    std::string s(p);

    std::cout << s << std::endl;

    return 0;
}
