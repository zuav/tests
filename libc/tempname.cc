#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>


const int NUM_TRIES = 10000;
const int BUF_SIZE = 512;


int main()
{
    long int t = time(0);
    char buf[BUF_SIZE];
    const char *dir = getcwd(0, 0);

    for (int i=0; i<NUM_TRIES; ++i) {
        if (snprintf(buf, BUF_SIZE, "%s/cdr%019ld.tmp", dir, t+i) >= BUF_SIZE) {
            std::cerr << "error: buffer too small\n";
            return 1;
        }
        if ((access(buf, F_OK) == -1) && (errno == ENOENT)) {
            std::cout << "temp filename:      " << buf     << '\n'
                      << "number of attempts: " << (i + 1) << '\n';
            return 0;
        }
    }

    std::cerr << "error: failed to create temp filename, number of attempts: "  << NUM_TRIES << '\n';

    return 1;
}
