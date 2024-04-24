#include <iostream>


#define PREFIX  "prefix: "

int main()
{
    const char *s = PREFIX "just string";

    std::cout << s << std::endl;

    return 0;
}
