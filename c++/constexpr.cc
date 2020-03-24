#include <iostream>


struct S1 {
    int i;
    char c;
};

struct S2 {
    int i;
    double d;
    char arr[10];
};

constexpr int MAX_SIZE = (sizeof(S1) > sizeof(S2)) ? sizeof(S1) : sizeof(S2);


int main()
{
    std::cout << "sizeof(S1): " << sizeof(S1) << std::endl
              << "sizeof(S2): " << sizeof(S2) << std::endl
              << "MAX_SIZE:   " << MAX_SIZE << std::endl;

    return 0;
}
