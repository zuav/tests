#include <vector>
#include <iostream>

int main()
{
    std::vector<const char *> v;

    std::cout << "vector size = " << v.size() << std::endl;

    v.push_back("0");
    v.push_back("1");
    v.push_back("2");
    v.push_back("3");
    v.push_back("4");
    v.push_back("5");
    v.push_back("6");
    v.push_back("7");
    v.push_back("8");
    v.push_back("9");

    std::cout << "vector size = " << v.size() << std::endl;

    typedef std::vector<const char *>::const_iterator CI;
    for (CI i=v.begin(), iend=v.end(); i!=iend; ++i)
        std::cout << *i << std::endl;

    return 0;
}
