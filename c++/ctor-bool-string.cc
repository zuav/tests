#include <iostream>
#include <string>


class Foo {
public:
    explicit Foo(bool) { std::cout << "Foo(bool) called" << std::endl; }
    explicit Foo(const std::string&)  { std::cout << "Foo(const std::string&) called" << std::endl; }
};


int main()
{
    Foo f("string");

    return 0;
}
