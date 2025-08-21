#include <errno.h>
#include <iostream>
#include <filesystem>
#include <exception>


namespace fs = std::filesystem;



int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << program_invocation_short_name << " dir-name" << std::endl;
        return 1;
    }

    fs::path dir { argv[1] };

    try {
        fs::create_directories(dir);
        std::cout << "created directory: " << dir << std::endl;
    }
    catch (std::exception& exc) {
        std::cerr << "error: failed to create directory '" << dir << "'; reason: " << exc.what() << std::endl;
        return 2;
    }

    return 0;
}
