#include <string>
#include <iostream>


int main()
{
    std::string s1 = "3147483647";
    unsigned v1 = std::stoul(s1);

    std::string s2 = "10223372036854775807";
    unsigned v2 = std::stoull(s2);

    std::cout << "s1 = " << s1 << std::endl
              << "v1 = " << v1 << std::endl
              << std::endl
              << "s2 = " << s2 << std::endl
              << "v2 = " << v2 << std::endl;


    return 0;
}
