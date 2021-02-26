#include <string>
#include <algorithm>
#include <iostream>


int main()
{
    std::string s1 { "a\nb\nc\nd\n" };
    std::string s2 = s1;
    std::replace(s2.begin(), s2.end(), '\n', ';');

    std::cout << s1 << s2 << std::endl;

    return 0;
}
