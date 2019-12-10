#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>


int main(int argc, char *argv[])
{
    std::ifstream is(argv[1]);
    std::vector<std::string> content;

    while (is) {
        std::string s;
        std::getline(is, s);
        content.push_back(s);
    }

    std::cout << "read lines: " << content.size() << '\n';

    typedef std::vector<std::string>::const_iterator CI;
    int ln = 0;
    for (CI k=content.begin(), kend=content.end(); k!=kend; ++k, ++ln)
        std::cout << "line " << std::setw(2) << ln << ": " << *k << '\n';

    return 0;
}
