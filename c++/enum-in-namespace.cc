#include <iostream>


namespace N1 {

    enum Enum_1 {
        A = 1
    };
}

namespace N2 {

    enum Enum_2 {
        A = 2
    };
}

int main()
{
    std::cout << "N1::A = " << N1::A << std::endl;

    return 0;
}
