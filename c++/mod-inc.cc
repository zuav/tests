#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " module limit" << std::endl;
        return 1;
    }

    int mod = std::stoi(argv[1]);
    int lim = std::stoi(argv[2]);

    std::cout << "module: " << mod << std::endl
              << "limit:  " << lim << std::endl;

    for (int i=0; i<lim; ++i)
        std::cout << i % mod << ' ';
    std::cout << std::endl;

    return 0;
}
