#include <iostream>
#include <iomanip>

int main()
{
    uint8_t byte[7] = { 0, 1, 3, 17, 128, 201, 255 };

    for (int i=0; i<7; ++i)
        std::cout << std::setw(2) << std::setfill('0') << std::hex << int(byte[i]) << std::endl;

    return 0;
}
