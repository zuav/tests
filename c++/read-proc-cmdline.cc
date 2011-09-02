#include <errno.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    std::ifstream is("/proc/cmdline");
    if (!is)
        std::cerr << "failed to open /proc/cmdline: " << strerror(errno) << std::endl;

    std::string s;
    while (is >> s)
        std::cout << s << std::endl;

    return 0;
}
