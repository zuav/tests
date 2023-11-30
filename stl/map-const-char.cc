#include <map>
#include <iostream>


int main()
{
    std::map<int, const char *> m;

    std::cout << "m[0] = '" << m[0] << "'" << std::endl;

    return 0;
}
