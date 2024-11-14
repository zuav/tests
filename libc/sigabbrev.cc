#include <string.h>
#include <errno.h>
#include <iostream>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << program_invocation_short_name << " sig_num" << std::endl;
        return 1;
    }

    int signum = std::stoi(argv[1]);

    std::cout << "signal number: " << signum << std::endl
              << "signal abbrev: " << sigabbrev_np(signum) << std::endl;

    return 0;
}
