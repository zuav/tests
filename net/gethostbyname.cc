#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <errno.h>
#include <iostream>


void error(const char *msg, int rc);


int main(int argc, char *argv[])
{
    char hostname[256];

    struct timeval tbeg;
    if (gettimeofday(&tbeg, 0) != 0) {
        std::cerr << "error: failed to get time of day: " << strerror(errno) << ": " << errno << std::endl;
        return 1;
    }
    time_t t1 = (tbeg.tv_sec * 1000000) + tbeg.tv_usec;

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

    struct timeval tend;
    if (gettimeofday(&tend, 0) != 0) {
        std::cerr << "failed to get time of day: " << strerror(errno) << ": " << errno << std::endl;
        return 1;
    }
    time_t t2 = (tend.tv_sec * 1000000) + tend.tv_usec;

    std::cout << "time spent (microseconds): " << t2 - t1 << std::endl;


    return 0;
}


void error(const char *msg, int rc)
{
    std::cerr << "errro: " << msg << "; rc: " << rc << ": " << strerror(rc) << std::endl;
    exit(1);
}
