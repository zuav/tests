#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <bitset>


int main(int argc, char *argv[])
{
    long v = std::strtol(argv[1], 0, 0);

    if (!((v >= 0) && (v <= 255))) {
        std::cerr << "error: bad argument, must in [0, 255] range: " << v << std::endl;
        return 1;
    }



    std::cout << "dec: " << std::ios::dec << v << std::endl
              << "hex: " << std::ios::hex << v << std::endl
              << "bin: " << std::bitset<8>(v).to_string() << std::endl;

    return 0;
}
