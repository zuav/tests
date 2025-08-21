#include <arpa/inet.h>
#include <iostream>


int main()
{
    in_addr addr_244_0;
    inet_aton("244.0.0.0", &addr_244_0);

    in_addr addr_244_255;
    inet_aton("244.0.0.255", &addr_244_255);

    in_addr addr_239_255;
    inet_aton("239.255.255.255", &addr_239_255);

    std::cout << "244.0.0.0:       " << addr_244_0.s_addr << std::endl
              << "244.0.0.255:     " << addr_244_255.s_addr << std::endl
              << "239.255.255.255: " << addr_239_255.s_addr << std::endl;

    return 0;
}
