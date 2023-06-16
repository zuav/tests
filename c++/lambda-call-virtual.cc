#include <iostream>
#include <functional>
#include <string>


using Pf = std::function<std::string()>;


struct A {
    void setup()
        {
            m_f = [this] () { return value(); };
        }
    void f()
        {
            std::cout << m_f() << std::endl;
        }

    Pf m_f;

    virtual std::string value() = 0;
};


struct B1 : public A {

    std::string value() { return "This is B1"; }
};

struct B2 : public A {

    std::string value() { return "This is B2"; }
};



int main(int argc, char *argv[])
{
    B1 b1;
    B2 b2;

    b1.setup();
    b2.setup();

    b1.f();
    b2.f();

    return 0;
}
