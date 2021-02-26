#include <iostream>

#define xstr(s) str(s)
#define str(s) #s
#define NUM 15

int main()
{
    const char *str = "The number is " xstr(NUM) ".";

    std::cout << str << std::endl;

    return 0;
}
