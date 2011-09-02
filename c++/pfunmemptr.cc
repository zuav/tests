#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

std::string bar("bar");

void foo()
{
    int i = 0;
    i++;
    bar[i] = 's';
}

void bas()
{
    int i = 0;
    i++;
    bar[i] = 's';
}

struct S {
    virtual void foo() { bar[0] = 'k'; }
};

struct SS {
    static void foo() { bar[0] = 'k'; }
};

int main()
{
    typedef void (*Pf) ();

    Pf pfoo = &foo;
    Pf pbas = &bas;

    std::cout << "sizeof(&foo)                = " << sizeof(pfoo) << std::endl
              << "sizeof(&std::string::c_str) = " << sizeof(&std::string::c_str) << std::endl
              << "sizeof(&S::foo)             = " << sizeof(&S::foo) << std::endl
              << "sizeof(&SS::foo)            = " << sizeof(&SS::foo) << std::endl
              << "sizeof(long)                = " << sizeof(long) << std::endl
              << "sizeof(long long)           = " << sizeof(long long) << std::endl
              << std::endl
              << std::hex << "&foo                = " << (unsigned long)pfoo << std::endl
              << std::hex << "&bas                = " << (unsigned long)pbas << std::endl
              << std::hex << "&std::string::c_str = " << &std::string::c_str << std::endl
              << std::hex << "&S::foo             = " << &S::foo << std::endl
              << std::hex << "&SS::foo            = " << (unsigned long)&SS::foo << std::endl
              << std::hex << "&pfoo               = " << &pfoo << std::endl
              << std::endl;

    printf("&foo = %p\n&std::string::c_str = %p\n", pfoo, &std::string::c_str);


    return 0;
}
