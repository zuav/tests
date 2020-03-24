#include <arpa/inet.h>
#include <iostream>


int main()
{
    const char *str = "0.0.0.0";

    struct in_addr addr;
    if (inet_aton(str, &addr) == 0) {
        std::cerr << "failed to convert " << str << " to network address\n";
        return 1;
    }

    std::cout << str << ": " << addr.s_addr << std::endl;


    struct in_addr inaddrany1 = { htonl(INADDR_ANY) };
    const char *strany1 = inet_ntoa(inaddrany1);

    std::cout << strany1 << ": " << inaddrany1.s_addr << std::endl;

    struct in_addr inaddrany2 = { INADDR_ANY };
    const char *strany2 = inet_ntoa(inaddrany2);

    std::cout << strany2 << ": " << inaddrany2.s_addr << std::endl;

    return 0;
}
