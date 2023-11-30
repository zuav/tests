#include <tuple>
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

    return 0;
}


std::tuple<int, double> foo()
{
    return { 5, 3.1415 };
}
