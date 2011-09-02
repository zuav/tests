#include <string>
#include <list>

struct S {
    typedef std::list<std::string> list;

    list l;
};

int main()
{
    S s;

    s.l.push_back("");

    return 0;
}
