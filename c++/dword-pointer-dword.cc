#include <iostream>
#include <iomanip>
#include <bitset>
#include <limits>

#pragma pack(1)
union Decoupled {
    struct {
        unsigned a;
        unsigned b;
    } decoupled;
    const unsigned char *p = 0;
};
#pragma pack()

int main()
{
    unsigned dw11 = 0;
    const unsigned char *pb11 = reinterpret_cast<const unsigned char *>(dw11);
    Decoupled d1;
    d1.p = pb11;
    unsigned dw12 = d1.decoupled.a;

    std::cout << "dw11 = " << std::setw(64) << std::bitset<32>(dw11)  << '\n'
              << "pb11 = "                  << std::bitset<64>((unsigned long) pb11) << '\n'
              << "d1.p = "                  << std::bitset<64>((unsigned long) d1.p) << '\n'
              << "d1.a = " << std::setw(64) << std::bitset<32>(d1.decoupled.a)  << '\n'
              << "d1.b = " << std::setw(64) << std::bitset<32>(d1.decoupled.b)  << '\n'
              << "dw12 = " << std::setw(64) << std::bitset<32>(dw12)  << '\n'
              << '\n';

    unsigned int dw21 = 123456789;
    const unsigned char *pb21 = reinterpret_cast<const unsigned char *>(dw21);
    Decoupled d2;
    d2.p = pb21;
    unsigned int dw22 = d2.decoupled.a;

    std::cout << "dw21 = " << std::setw(64) << std::bitset<32>(dw21)  << '\n'
              << "pb21 = "                  << std::bitset<64>((unsigned long) pb21) << '\n'
              << "d2.p = "                  << std::bitset<64>((unsigned long) d2.p) << '\n'
              << "d2.a = " << std::setw(64) << std::bitset<32>(d2.decoupled.a)  << '\n'
              << "d2.b = " << std::setw(64) << std::bitset<32>(d2.decoupled.b)  << '\n'
              << "dw22 = " << std::setw(64) << std::bitset<32>(dw22)  << '\n'
              << '\n';

    unsigned int dw31 = std::numeric_limits<unsigned>::max();
    const unsigned char *pb31 = reinterpret_cast<const unsigned char *>(dw31);
    Decoupled d3;
    d3.p = pb31;
    unsigned int dw32 = d3.decoupled.a;

    std::cout << "dw31 = " << std::setw(64) << std::bitset<32>(dw31)  << '\n'
              << "pb31 = "                  << std::bitset<64>((unsigned long) pb31) << '\n'
              << "d3.p = "                  << std::bitset<64>((unsigned long) d3.p) << '\n'
              << "d3.a = " << std::setw(64) << std::bitset<32>(d3.decoupled.a)  << '\n'
              << "d3.b = " << std::setw(64) << std::bitset<32>(d3.decoupled.b)  << '\n'
              << "dw32 = " << std::setw(64) << std::bitset<32>(dw32)  << '\n';

    return 0;
}
