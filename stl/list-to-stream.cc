#include <list>
#include <iostream>

int main()
{
    std::list<int> l;

    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    std::cout << l << std::endl;

    return 0;
}
