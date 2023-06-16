#include <iostream>

const char str1[] = "abc"
    "def";

const char str2[] = "ghi" \
    "jkl";

int main()
{
    std::cout << str1 << std::endl
              << str2 << std::endl;

    return 0;
}
