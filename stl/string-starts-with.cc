#include <iostream>
#include <string>


int main()
{
    std::cout << std::boolalpha
              << "std::string().starts_with(std::string())      : " << std::string().starts_with(std::string())        << std::endl
              << "std::string(\"abc\").starts_with(std::string()) : " << std::string("abc").starts_with(std::string()) << std::endl
              << "std::string().starts_with(std::string(\"abc\")) : " << std::string().starts_with(std::string("abc"))      << std::endl;

    return 0;
}
