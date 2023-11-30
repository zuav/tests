#include <iostream>


int main()
{
    int v = 0;
    std::cout << v << std::endl;

    for (int i=0; i<6; ++i) {
        v ^= 1;
        std::cout << v << std::endl;
    }

    return 0;
}
