#include <string.h>
#include <iostream>
#include <string>
#include <uuid/uuid.h>


int main(int argc, char *argvp[])
{
    std::string idstr = "f8f96aeb-397a-4868-8537-18f927c3e99f";
    uuid_t id1 = { 248, 249, 106, 235, 57, 122, 72, 104, 133, 55, 24, 249, 39, 195, 233, 159 };

    uuid_t id2;
    if (uuid_parse(idstr.c_str(), id2) != 0) {
        std::cerr << "error: uuid_parse failed for string: " << idstr << std::endl;
        return 1;
    }

    if (memcmp(id1, id2, sizeof(uuid_t)) != 0) {
        std::cerr << "error: parsed id value is not equal to expected" << std::endl;
        return 1;
    }

    return 0;
}
