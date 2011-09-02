#include <boost/lexical_cast.hpp>
#include <iostream>

int main()
{
    std::string s = boost::lexical_cast<std::string>(64000+1);

    std::cout << s << std::endl;

    return 0;
}
