#include <format>
#include <iostream>


int main()
{
    std::string s = std::format("{}: parsing error: {}", 23, "some error");

    std::cin << s << std::endl;

    return 0;
}
