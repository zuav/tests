#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <sys/uio.h>
#include <iostream>


int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << program_invocation_short_name << " socket id num" << std::endl;
        return 1;
    }

    const char *sockname = argv[1];
    std::string id = argv[2];
    int num = std::stoi(argv[3]);

    std::cout << "socket name: " << sockname << std::endl
              << "message id:  " << id       << std::endl
              << "loop limit:  " << num      << std::endl;

    int sock = socket(AF_LOCAL, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "failed to create socket: " << errno << ": " << strerror(errno) << std::endl;
        return 1;
    }

    struct sockaddr_un addr;
    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, sockname, sizeof(addr.sun_path));
    addr.sun_path[sizeof(addr.sun_path) - 1] = '\0';

    for (int i=0; i<num; ++i) {
        struct iovec vec[5];
        std::string s[5];
        for (int j=0; j<5; j++) {
            s[j] = id + "-" + std::to_string(j*i+j);
            vec[j].iov_base = const_cast<char *>(s[j].c_str());
            vec[j].iov_len = s[j].size();
        }

        struct mmsghdr msg[5];
        memset(msg, 0, sizeof(msg));
        for (int i=0; i<5; ++i) {
            msg[i].msg_hdr.msg_name    = &addr;
            msg[i].msg_hdr.msg_namelen = sizeof(addr);
            msg[i].msg_hdr.msg_iov     = &vec[i];
            msg[i].msg_hdr.msg_iovlen  = 1;
        }

        int rc = sendmmsg(sock, msg, 5, 0);
        if (rc != -1)
            std::cout << "sendmmsg sent messages: " << rc << std::endl;
        else {
            std::cerr << "sendmmsg failed: " << errno << ": " << strerror(errno) << std::endl;
            sleep(3);
        }
    }

    return 0;
}
