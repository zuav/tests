#include <chrono>
#include <iostream>


int main()
{
    auto to = std::chrono::milliseconds(1000);

    std::cout << "sizeof to.count() : " << sizeof(decltype(to.count())) << std::endl;

    return 0;
}
