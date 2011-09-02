#include <errno.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << program_invocation_short_name << " pid" << std::endl;
        return 1;
    }

    std::string procdirname = "/proc/" + std::string(argv[1]);

    bool exists = (access(procdirname.c_str(), F_OK) == 0) ? true : false;

    std::cout << "proccess with pid '" << argv[1] << (exists ? "' is exists" : "' does not exists") << std::endl;

    return 0;
}

