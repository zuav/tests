#include <iostream>

struct Foo {
    typedef int Type;

    void f(Type);
};

void Foo::f(Type t)
{
    std::cout << t;
}
