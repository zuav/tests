#include <iostream>

void foo();

int main()
{
    foo();

    return 0;
}

void foo()
{
    class Bar {
    public:
        Bar() { std::cout << "Bar ctor" << std::endl; }
    };

    Bar bar;
}

