#include <iostream>
#include <string>

int main()
{
    while (!std::cin.eof()) {
        std::string s;
        getline(std::cin, s);
        if (s.size() == 0)
            std::cout << "read empty string" << std::endl;
        else
            std::cout << "read string: " << s << std::endl;
    }


    std::cout << "EOF of the infput stream" << std::endl;

    return 0;
}
