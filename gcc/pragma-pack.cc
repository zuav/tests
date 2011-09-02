#include <stdint.h>
#include <iostream>

#pragma pack(1)

struct Map_packed {
    uint16_t ntf_code;
    int32_t  extra_counter;
    uint16_t id_num;
};

#pragma pack()

struct Map_unpacked {
    uint16_t ntf_code;
    int32_t  extra_counter;
    uint16_t id_num;
};

int main()
{
    std::cout << "sizeof(Mac_packed)   = " << sizeof(Map_packed) << std::endl
              << "sizeof(Mac_unpacked) = " << sizeof(Map_unpacked) << std::endl;
}
