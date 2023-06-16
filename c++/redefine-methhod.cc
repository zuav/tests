#include <iostream>


class A {
public:
    void foo() { std::cout << "A::foo\n"; }
};

class B : public A {
public:
    void foo() { std::cout << "B::foo\n"; }
};
