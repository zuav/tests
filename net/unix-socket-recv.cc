#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <iostream>


int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cerr << "Usage: " << program_invocation_short_name << " socket" << std::endl;
        return 1;
    }

    const char *sockname = argv[1];

    int sock = socket(AF_LOCAL, SOCK_DGRAM, 0);
    if (sock == -1) {
        std::cerr << "error: failed to create socket for name: " << sockname << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

    struct sockaddr_un addr;
    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, sockname, sizeof(addr.sun_path));
    addr.sun_path[sizeof(addr.sun_path) - 1] = '\0';

    if (bind(sock, (struct sockaddr *) &addr, SUN_LEN(&addr)) < 0) {
        std::cerr << "error: failed to bind socket for name: " << sockname << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

    while (true) {
        char buf[128];
        memset(buf, 0, sizeof(buf));
        int rc = recv(sock, buf, sizeof(buf), 0);
        if (rc == -1) {
            if (errno == EINTR) {
                std::cerr << "got signal, exiting" << std::endl;
                break;
            }
            std::cerr << "recv failed: " << errno << ": " << strerror(errno) << std::endl;
            continue;
        }
        std::cout << buf << std::endl;
    }

    unlink(sockname);

    return 0;
}
