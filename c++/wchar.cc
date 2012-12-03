#include <iostream>

int main()
{
    wchar_t wc;
    wchar_t wbuf[1024];

    std::cout << "wc size:   " << sizeof(wc) << std::endl
              << "wbuf size: " << sizeof(wbuf) << std::endl;

    return 0;
}
