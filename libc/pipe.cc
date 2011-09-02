#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

int main()
{
	int fd[2];
	if (::pipe(fd) == -1) {
        std::cerr << "pipe error: " << strerror(errno) << std::endl;
        return 1;
    }

    // 	m_readfd = fd[0];
    // 	m_writefd = fd[1];
    char c;
    if (::read(fd[0], &c, 1) == -1) {
        std::cerr << "read error: " << strerror(errno) << std::endl;
        return 1;
    }

    return 0;
}
