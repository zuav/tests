#include <iostream>

struct Foo {
    virtual ~Foo() throw() {}
    virtual void f() throw() { std::cout << "this is Foo::f()" << std::endl; }
};

struct Bar : public Foo {};

int main()
{
    Bar b;

    b.f();
}
