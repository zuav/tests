#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdexcept>


size_t sock_buf_size(int sock, int optname)
{
    socklen_t optlensz = sizeof(size_t);
    size_t bufsz = 0;

    if (getsockopt(sock, SOL_SOCKET, optname, &bufsz, &optlensz) != 0) {
        std::string optstr;
        if (optname == SO_SNDBUF)
            optstr = "SO_SNDBUF";
        else if (optname == SO_RCVBUF)
            optstr = "SO_RCVBUF";
        else
            optstr = std::to_string(optname);
        throw std::runtime_error("failed getsockopt for " + optstr + ": " + strerror(errno));
    }

    return bufsz;
}


void set_sock_buf_size(int sock, int optname, size_t bufsz)
{
    socklen_t optlensz = sizeof(size_t);

    if (setsockopt(sock, SOL_SOCKET, optname, &bufsz, optlensz) != 0) {
        std::string optstr;
        if (optname == SO_SNDBUF)
            optstr = "SO_SNDBUF";
        else if (optname == SO_RCVBUF)
            optstr = "SO_RCVBUF";
        else
            optstr = std::to_string(optname);
        throw std::runtime_error("failed getsockopt for " + optstr + ": " + strerror(errno));
    }
}


int main()
{
    int fds[2] = { 0, 0 };
    int rc = socketpair(AF_LOCAL, SOCK_STREAM, 0, fds);

    if (rc != 0) {
        std::cerr << "socketpair failed; error: " << errno << ": " << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "socket pair was created successfully" << std::endl
              << "fds[0] send buffer size: " << sock_buf_size(fds[0], SO_SNDBUF) << std::endl
              << "fds[0] recv buffer size: " << sock_buf_size(fds[0], SO_RCVBUF) << std::endl
              << "fds[1] send buffer size: " << sock_buf_size(fds[1], SO_SNDBUF) << std::endl
              << "fds[1] recv buffer size: " << sock_buf_size(fds[1], SO_RCVBUF) << std::endl;

    set_sock_buf_size(fds[0], SO_SNDBUF, 212992);
    set_sock_buf_size(fds[1], SO_RCVBUF, 212992);

    std::cout << "new buffer sizes:" << std::endl
              << "fds[0] send buffer size: " << sock_buf_size(fds[0], SO_SNDBUF) << std::endl
              << "fds[1] recv buffer size: " << sock_buf_size(fds[1], SO_RCVBUF) << std::endl;

    return 0;
}
