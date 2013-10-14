#include <iostream>
#include <stdexcept>

int main()
{
    std::system_error exc(2, std::system_category());

    std::cout << "error code:    " << exc.code() << std::endl
              << "error message: " << exc.code().message() << std::endl
              << "what:          " << exc.what() << std::endl;

    return 0;
}
