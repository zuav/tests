#include <stdio.h>

struct A {
    int i;
    double d;
};

struct B {
    int ii;
    double dd;
};

struct C {
    float f;
    char s[2];
};


void foo(struct A *pa)
{
    printf("%d\n", pa->i);
}


int main()
{
    struct B b = { 5, 10.0 };
    foo(&b);

    struct C c = { 5.0, { 'a', 'b' } };
    foo(&c);

    return 0;
}
