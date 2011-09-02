#include <iostream>
#include <boost/bind.hpp>

struct F {
    F(int v) : i(v) {}

    int set(int v) { int t = i; i = v; return t; }

    int i;
};

typedef int (*Pfunc)();

template <typename Pfunc>
void bar(Pfunc pf)
{
    int v = pf();
    std::cout << "pf call result: " << v << std::endl;
}

int main()
{
    F f(5);

    bar(boost::bind(&F::set, &f, 7));

    std::cout << "f.i : " << f.i << std::endl;
}
