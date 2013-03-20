#include <iostream>
#include <iomanip>



class A {
public:
	A();
	virtual ~A();
};

class B : public A {
public:
	B();
	~B();
};


A::A() {}
A::~A() {}
B::B() {}
B::~B() {}


int main()
{
	A *pa = dynamic_cast<A*>(new B);
	B *pb = dynamic_cast<B*>(pa);

    std::cout << "pa = " << std::hex << pa << std::endl;
    std::cout << "pb = " << std::hex << pb << std::endl;

	delete pa;

	return 0;
}
