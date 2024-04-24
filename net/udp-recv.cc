#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>


int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cerr << "Usage: " << program_invocation_short_name << " port" << std::endl;
        return 1;
    }

    uint16_t port = std::stoi(argv[1]);

    int sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        std::cerr << "error: failed to create socket for port " << port << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (bind(sock, (struct sockaddr *) &name, sizeof (name)) < 0) {
        std::cerr << "error: failed to bind socket for port " << port << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

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
