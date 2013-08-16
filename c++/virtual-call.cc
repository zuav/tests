#include <iostream>

struct Base {

    void f() { this->virt(); }
    virtual void virt() { std::cout << "Base virt() called" << std::endl; }
};

struct Derived : public Base {

    void virt() { std::cout << "Derived virt() called" << std::endl; }
};


int main()
{
    Derived d;
    d.f();

    return 0;
}
