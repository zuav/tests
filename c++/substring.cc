#include <string>
#include <iostream>

int main()
{
    std::string s = "/abc/def/ghji.ext";
    std::string s1 = "1234567.ext";

    std::cout << "s = "         << s                            << std::endl
              << "sub str = "   << s.substr(s.rfind('/') + 1)   << std::endl
              << "s1 = "        << s1                           << std::endl
              << "sub str 1 = " << s1.substr(s1.rfind('/') + 1) << std::endl;

    return 0;
}
