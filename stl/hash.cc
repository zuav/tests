#include <iostream>
#include <string>


int main()
{
    std::hash<std::string> make_hash;

    size_t h1 = make_hash("one");
    size_t h2 = make_hash("two");
    size_t h3 = make_hash("three");

    std::cout << "h1 = " << h1 << std::endl
              << "h2 = " << h2 << std::endl
              << "h3 = " << h3 << std::endl;

    return 0;
}
