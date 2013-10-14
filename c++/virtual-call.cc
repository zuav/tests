#include <iostream>

struct Base {

    void f() { this->virt(); }
    void pure() { pure_virt(); }

    virtual void pure_virt()  = 0;
    virtual void virt() { std::cout << "Base virt() called" << std::endl; }
};

struct Derived : public Base {

    Derived() { pure(); }

    void virt() { std::cout << "Derived virt() called" << std::endl; }
    void pure_virt() { std::cout << "Derived pure_virt() called" << std::endl; }
};


int main()
{
    Derived d;
    d.f();

    return 0;
}
