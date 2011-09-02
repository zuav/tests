#include <iostream>

namespace N {

    static int i = 10;

    void foo();
}

void N::foo()
{
    i = 100;
}

int main()
{
    std::cout << "N::i = " << N::i << std::endl;

    N::foo();

    std::cout << "N::i = " << N::i << std::endl;

    return 0;
}
