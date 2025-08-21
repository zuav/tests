struct A {

    struct B;

    int a1;
    int a2;
};

struct A::B {
    int b1;
    int b2;
};

int main()
{
    A a;
    A::B b;

    return 0;
}
