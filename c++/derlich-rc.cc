#include <iostream>

struct S {
    static int i;
    S() { ++i; }
    S(const S&) { ++i; }
};

int S::i = 0;

int main()
{
    S v(S());
    // S v;

    std::cout << v.i << std::endl;

    return S::i;
}

