#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace Test {

    template <typename Exception, typename Type>
    void error(const std::string& msg, Type param)
    {
        std::stringstream ss;
        ss << msg << ": " << param;
        throw Exception(ss.str());
    }

}

using Test::error;

int main()
{
    try {
        int v = 10;
        error<std::runtime_error>("runtime error; value", v);
    }
    catch (std::exception& exc) {
        std::cout << "got exception: " << exc.what() << std::endl;
    }

    try {
        const char *p = "infinity";
        error<std::invalid_argument>("invalid argument; value", p);
    }
    catch (std::exception& exc) {
        std::cout << "got exception: " << exc.what() << std::endl;
    }

    return 0;
}
