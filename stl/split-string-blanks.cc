#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>


int main()
{
    std::string s = "What  is the    right way   to split a string        into  \ta vector of strings";
    std::istringstream ss(s);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);

    std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}
