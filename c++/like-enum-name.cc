#include <iostream>

class Foo {
public:
    enum {
        FT_GOOD,
        FT_BAD
    };

    Foo(int);

    void out_good() const;

private:
    int f;
};

Foo::Foo(int v) : f(v)
{
}

void Foo::out_good() const
{
    std::cout << "FT_GOOD: " << FT_GOOD << std::endl;
}

const Foo FT_GOOD(Foo::FT_GOOD);

int main()
{
    FT_GOOD.out_good();

    return 0;
}

