#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <iostream>


int main(int argc, char *argv[])
{
    if ((argc < 2) || (argc > 3)) {
        std::cerr << "Usage: " << program_invocation_short_name << " port [if_name]" << std::endl;
        return 1;
    }

    uint16_t port = std::stoi(argv[1]);
    const char *ifname = 0;
    if (argc == 3) {
        if (strlen(argv[2]) >= IFNAMSIZ) {
            std::cerr << "error: if_name length must not more than " << (IFNAMSIZ - 1) << std::endl;
            exit(1);
        }
        ifname = argv[2];
    }

    int sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        std::cerr << "error: failed to create socket for port " << port << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

    if (ifname) {
        if (setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, ifname, strlen(ifname)+1) != 0) {
            std::cerr << "error: bind socket to interface '" << ifname << "': " << strerror(errno) << ": " << errno << std::endl;
            exit(1);
        }

        char buf[IFNAMSIZ];
        socklen_t bufsz = sizeof(buf);
        if (getsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, buf, &bufsz) != 0) {
            std::cerr << "error: bind socket to interface '" << ifname << "': " << strerror(errno) << ": " << errno << std::endl;
            exit(1);
        }

        std::cout << "socket " << sock << " binded to device: " << buf << std::endl;
    }

    sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    // name.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (sockaddr *) &name, sizeof (name)) < 0) {
        std::cerr << "error: failed to bind socket for port " << port << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

    sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    if (getsockname(sock, (sockaddr *) &addr, &addrlen) < 0) {
        std::cerr << "error: failed to get sock name: " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

    char buf[16];
    std::string ip = inet_ntop(AF_INET, &addr.sin_addr.s_addr, buf, sizeof(buf));
    int localport = ntohs(addr.sin_port);

    std::cout << "socket name is: " << ip << ':' << localport << std::endl;

    while (true) {
        char buf[128];
        memset(buf, 0, sizeof(buf));
        int rc = recv(sock, buf, sizeof(buf), 0);
        if (rc == -1) {
            std::cerr << "recv failed: " << errno << ": " << strerror(errno) << std::endl;
            continue;
        }
        std::cout << buf << std::endl;
    }

    return 0;
}
