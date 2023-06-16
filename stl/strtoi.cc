#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
    std::string s = "543 Oblom";

    std::cout << "s               : " << s << std::endl
              << "std::stoi(s)    : " << std::stoi(s) << std::endl
              // << "std::stoul(" ") : " << std::stoul(" ") << std::endl
              << "std::stoul("")  : " << std::stoul(std::string()) << std::endl;

    return 0;
}
