#include <stdlib.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <iostream>


static void open_udp_port(uint32_t, short);


int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << program_invocation_short_name << " IP num_of_udp_ports start_port_num" << std::endl;
        return 1;
    }

    std::string ipstr = argv[1];
    struct in_addr addr;
    if (inet_aton(ipstr.c_str(), &addr) == 0) {
        std::cerr << "error: invalid IP address: " << ipstr << std::endl;
        return 1;
    }
    uint32_t ip = addr.s_addr;

    short numsocks = static_cast<short>(strtol(argv[2], 0, 0));
    if (numsocks < 1) {
        std::cerr << "error: num_of_udp_ports must be greater than 0: " << numsocks << std::endl;
        return 1;
    }

    short startport = static_cast<short>(strtol(argv[3], 0, 0));
    if (startport < 1) {
        std::cerr << "error: start_port_num must be greater than 0: " << startport << std::endl;
        return 1;
    }

    std::cout << "IP:                        " << ipstr << std::endl
              << "Number of UDP ports:       " << numsocks << std::endl
              << "starting port:             " << startport << std::endl;

    struct timeval tbeg;
    if (gettimeofday(&tbeg, 0) != 0) {
        std::cerr << "error: failed to get time of day: " << strerror(errno) << ": " << errno << std::endl;
        return 1;
    }
    time_t t1 = (tbeg.tv_sec * 1000000) + tbeg.tv_usec;

    for (short i = 0; i<numsocks; ++i)
        open_udp_port(ip, startport+i);

    struct timeval tend;
    if (gettimeofday(&tend, 0) != 0) {
        std::cerr << "failed to get time of day: " << strerror(errno) << ": " << errno << std::endl;
        return 1;
    }
    time_t t2 = (tend.tv_sec * 1000000) + tend.tv_usec;

    // std::cout << "t1: " << t1 << std::endl
    //           << "t2: " << t2 << std::endl;

    std::cout << "time spent (microseconds): " << t2 - t1 << std::endl;

    return 0;
}


void open_udp_port(uint32_t ip, short port)
{
    int sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        std::cerr << "error: failed to create socket for port " << port << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = ip;

    if (bind(sock, (struct sockaddr *) &name, sizeof (name)) < 0) {
        std::cerr << "error: failed to bind socket for port " << port << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }
}
