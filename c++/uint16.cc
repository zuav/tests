#include <stdint.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

// 65535


int main()
{
    uint16_t v1 = 5;
    uint16_t v2 = 65530;

    int d1 = abs(v2 - v1);
    int d2 = v1 + (UINT16_MAX + 1 - v2);

    std::cout << v1 << " - " << v2 << " = " << uint16_t(v1 - v2) << std::endl
              << std::min(d1, d2) << std::endl;

    return 0;
}
