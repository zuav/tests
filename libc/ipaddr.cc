#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: ipaddr {s2i ip_string | i2s ip_integer}" << std::endl;
        return 1;
    }

    if (std::string(argv[1]) == std::string("s2i")) {
        const char *ipstr = argv[2];
        struct in_addr addr;
        if (inet_aton(ipstr, &addr) == 0) {
            std::cerr << "error: addr is not valid: " << ipstr << std::endl;
            return 2;
        }
        std::cout << "IP as string:                   " << ipstr << std::endl
                  << "IP as int (network byte order): " << addr.s_addr << std::endl
                  << "IP as int (host byte order):    " << ntohl(addr.s_addr) << std::endl;
    } else if (std::string(argv[1]) == std::string("i2s")) {
        uint32_t ipint = strtoul(argv[2], 0, 0);
        struct in_addr addr;
        addr.s_addr = htonl(ipint);
        const char *ipstr = inet_ntoa(addr);
        std::cout << "IP as int (host byte order):    " << ipint << std::endl
                  << "IP as int (network byte order): " << addr.s_addr << std::endl
                  << "IP as string:                   " << ipstr << std::endl;
    } else {
        std::cerr << "error: unknown command: " << argv[1] << std::endl;
        return 2;
    }

    return 0;
}
