#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>


void error(const char *msg, int rc);


int main(int argc, char *argv[])
{
    char hostname[256];

    if (argc == 2) {
        snprintf(hostname, sizeof(hostname), "%s", argv[1]);
    } else if (argc == 1) {
        int rc = gethostname(hostname, sizeof(hostname));
        if (rc != 0)
            error("gethostname failed", rc);
    } else {
        std::cerr << "error: too many arguments\n";
        return 1;
    }

    struct hostent *hostent = gethostbyname(hostname);
    if(!hostent)
        error("gethostbyname failed", h_errno);

    std::cout << "h_name:         " << hostent->h_name << '\n'
              << "h_addrtype:     " << hostent->h_addrtype << '\n'
              << "h_length:       " << hostent->h_length << '\n';

    for (int i=0; hostent->h_addr_list[i]; ++i) {
        struct in_addr naddr;
        memcpy(&naddr, hostent->h_addr_list[i], sizeof(naddr));
        const char *saddr = inet_ntoa(naddr);
        std::cout << "h_addr_list[" << i << "]: " << saddr << '\n';
    }

    return 0;
}


void error(const char *msg, int rc)
{
    std::cerr << "errro: " << msg << "; rc: " << rc << ": " << strerror(rc) << std::endl;
    exit(1);
 }
