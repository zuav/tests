#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <iostream>


struct S1 {
    int code;
    int data;
};


struct S2 {
    int code;
    int data;
    char uuid[16];
};



int main()
{
    std::cout << "PIPE_BUF: " << PIPE_BUF << std::endl
              << std::endl;

    int spipe[2];

    if (pipe(spipe) != 0) {
        std::cerr << "error: failed to create pipe: " << errno << std::endl;
        return 1;
    }

    int oldflags = fcntl(spipe[1], F_GETFL, 0);
    if (oldflags == -1) {
        std::cerr << "error: fcntl GET failed for pipe write end: " << errno << std::endl;
        return 2;
    }

    oldflags |= O_NONBLOCK;

    if (fcntl(spipe[1], F_SETFL, oldflags) == -1) {
        std::cerr << "error: fcntl SET failed for pipe write end: " << errno << std::endl;
        return 3;
    }

    std::cout << "writing " << sizeof(S1) << " bytes per write into pipe" << std::endl;
    int cnt01 = 0;
    while (true) {
        S1 s;
        int rc = write(spipe[1], &s, sizeof(s));
        if (rc != sizeof(s)) {
            if (errno == EWOULDBLOCK)
                break;
            else {
                std::cerr << "error: write failed: " << errno << std::endl;
                return 4;
            }
        }
        cnt01++;
    }
    std::cout << "  written chunks: " << cnt01 << std::endl
              << "  size in bytes:  " << cnt01 * sizeof(S1) << std::endl
              << std::endl;

    close(spipe[0]);
    close(spipe[1]);

    //
    //
    //

    if (pipe(spipe) != 0) {
        std::cerr << "error: failed to create pipe: " << errno << std::endl;
        return 1;
    }

    oldflags = fcntl(spipe[1], F_GETFL, 0);
    if (oldflags == -1) {
        std::cerr << "error: fcntl GET failed for pipe write end: " << errno << std::endl;
        return 2;
    }

    oldflags |= O_NONBLOCK;

    if (fcntl(spipe[1], F_SETFL, oldflags) == -1) {
        std::cerr << "error: fcntl SET failed for pipe write end: " << errno << std::endl;
        return 3;
    }

    std::cout << "writing " << sizeof(S2) << " bytes per write into pipe" << std::endl;
    int cnt02 = 0;
    while (true) {
        S2 s;
        int rc = write(spipe[1], &s, sizeof(s));
        if (rc != sizeof(s)) {
            if (errno == EWOULDBLOCK)
                break;
            else {
                std::cerr << "error: write failed: " << errno << std::endl;
                return 4;
            }
        }
        cnt02++;
    }
    std::cout << "  written chunks: " << cnt02 << std::endl
              << "  size in bytes:  " << cnt02 * sizeof(S2) << std::endl;

    close(spipe[0]);
    close(spipe[1]);

    return 0;
}
