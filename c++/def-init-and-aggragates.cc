#include <iostream>

struct S0 {
    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
};

struct S1 {
    int i1 { 1 };
    int i2 { 2 };
    int i3 { 3 };
};


int main(int, char *[])
{
    S0 s0 {};
    S1 s1 {};

    std::cout << "S0.i1 = " << s0.i1 << std::endl
              << "S0.i2 = " << s0.i2 << std::endl
              << "S0.i3 = " << s0.i3 << std::endl
              << std::endl
              << "S1.i1 = " << s1.i1 << std::endl
              << "S1.i2 = " << s1.i2 << std::endl
              << "S1.i3 = " << s1.i3 << std::endl
              << std::endl;

    return 0;
}
