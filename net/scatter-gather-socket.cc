#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
//#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>


int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cerr << "Usage: ./a.out port" << std::endl;
        return 1;
    }

    uint16_t port = std::stoi(argv[1]);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "failed to create socket: " << errno << ": " << strerror(errno) << std::endl;
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    addr.sin_port = htons(port);

    struct iovec vec[5] {
        { const_cast<char *>("one"),   strlen("one")   },
        { const_cast<char *>("two"),   strlen("two")   },
        { const_cast<char *>("three"), strlen("three") },
        { const_cast<char *>("four"),  strlen("four")  },
        { const_cast<char *>("five"),  strlen("five")  }
    };

    struct mmsghdr msg[5];
    memset(msg, 0, sizeof(msg));
    for (int i=0; i<5; ++i) {
        msg[i].msg_hdr.msg_name    = &addr;
        msg[i].msg_hdr.msg_namelen = sizeof(addr);
        msg[i].msg_hdr.msg_iov     = const_cast<struct iovec*>(&vec[i]);
        msg[i].msg_hdr.msg_iovlen  = 1;
    }

    int rc = sendmmsg(sock, msg, 5, 0);
    if (rc != -1)
        std::cout << "sendmmsg sent messages: " << rc << std::endl;
    else {
        std::cerr << "sendmmsg failed: " << errno << ": " << strerror(errno) << std::endl;
        return 1;
    }

    return 0;
}
