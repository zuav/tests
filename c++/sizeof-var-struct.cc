#include <iostream>

#pragma pack(1)

struct Map {
    uint16_t room_name_len;
    uint16_t user_name_len;
    char     data[];
};

#pragma pack()


int main()
{
    std::cout << "sizeof(Map) = " << sizeof(Map) << std::endl;

    return 0;
}
