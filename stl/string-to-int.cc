#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << program_invocation_short_name << " number" << std::endl;
        return 1;
    }

    std::string s = argv[1];

    std::cout << "s = " << s << std::endl
              << "i = " << std::stoi(s) << std::endl
              << "l = " << std::stol(s) << std::endl;

    return 0;
}
