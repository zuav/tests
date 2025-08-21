#include <iostream>

namespace VS {

    namespace IGW {

        namespace Test {

            struct S {
                int v = 1;

                void f();
            };
        }
    }
}


void VS::IGW::Test::S::f()
{
    std::cout << __PRETTY_FUNCTION__ << ": " << v << std::endl;
}


int main()
{
    VS::IGW::Test::S s;
    s.f();

    return 0;
}
