#include <iostream>


namespace VS {

    namespace IGW {

        namespace Test {

            class A;
        }


        namespace Stream {

            class B {
            protected:
                short s1 = 11;
                short s2 = 12;
            };

            class A  : public B {
                friend Test::A;
                // friend class Test_A;

                int i = 1;
                long l = 10;
            };
        }
    }
}

namespace VS {

    namespace IGW {

        namespace Test {

            class A : public VS::IGW::Stream::A {
            public:
                void set_i(int v) { i = v; }
                void set_l(long v) { l = v; }
                void set_s1(short v) { s1 = v; }
                void set_s2(short v) { s2 = v; }

                void print_data() { std::cout << "i = " << i << "; l = " << l  << "; s1 = " << s1 << "; s2 = " << s2 << std::endl; }
            };
        }
    }
}


int main(int argc, char *argv[])
{
    // Test_A b;
    VS::IGW::Test::A b;

    b.set_i(2);
    b.set_l(20);
    b.set_s1(111);
    b.set_s2(112);

    b.print_data();

    return 0;
}
