#include <iostream>


struct IP_str {
    char ip;

    IP_str(const char *);
};


IP_str::IP_str(const char *s)
{
    strccpy(ip, s, 16);
}


char *operator=(char dst[16], IP_str)
{
    memcpy(dst, ip, 16);

    return dst;
}


int main()
{
    IP_str ips {"127.0.0.1"};
    char ipa[16];

    ipa = ips;

    std::cout << "ipa = " << ipa << std::endl;

    return 0;
}
