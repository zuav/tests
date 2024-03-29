#include <stdint.h>
#include <iostream>

#pragma pack(1)

struct Map_packed {
    uint16_t ntf_code;
    int32_t  extra_counter;
    uint16_t id_num;
};

struct Header_packed {
    unsigned char type;
    unsigned char payload;
    unsigned char length;
    unsigned char magic;
};


#pragma pack()

struct Map_unpacked {
    uint16_t ntf_code;
    int32_t  extra_counter;
    uint16_t id_num;
};

struct Header_unpacked {
    unsigned char type;
    unsigned char payload;
    unsigned char length;
    unsigned char magic;
};


int main()
{
    std::cout << "sizeof(Map_packed)      = " << sizeof(Map_packed)      << std::endl
              << "sizeof(Map_unpacked)    = " << sizeof(Map_unpacked)    << std::endl
              << "sizeof(Header_packed)   = " << sizeof(Header_packed)   << std::endl
              << "sizeof(Header_unpacked) = " << sizeof(Header_unpacked) << std::endl;
}
