#include <chrono>
#include <iostream>


int main()
{
    int i1 = 5;
    std::chrono::milliseconds ms { i1 };

    std::cout << "i1 = " << i1 << std::endl
              << "ms = " << ms.count() << std::endl;

    int i2 = 7;
    std::chrono::seconds ss { i2 };

    std::cout << "i2 = " << i2 << std::endl
              << "ss = " << ss.count() << std::endl;

    int i3 = 9;
    std::chrono::nanoseconds ns { i3 };

    std::cout << "i3 = " << i3 << std::endl
              << "ns = " << ns.count() << std::endl;

    return 0;
}
