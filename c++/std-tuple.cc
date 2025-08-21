#include <tuple>
#include <vector>
#include <iostream>


struct S {
    int i;
    double d;
};


std::tuple<int, double> foo();


int main()
{
    const auto [i, d] = foo();

    std::cout << "i = " << i << std::endl
              << "d = " << d << std::endl;


    S s;
    int &ii = s.i;
    double &dd = s.d;

    [ii, dd] = foo();

    std::cout << "s.i = " << s.i << std::endl
              << "s.d = " << s.d << std::endl;

    std::vector<int> v { 1, 2, 3 };
    auto [i1, i2, i3] = v;

    std::cout << "i1 = " << i1 << std::endl
              << "i2 = " << i2 << std::endl
              << "i3 = " << i3 << std::endl;


    return 0;
}


std::tuple<int, double> foo()
{
    return { 5, 3.1415 };
}
