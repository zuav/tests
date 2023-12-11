#include <set>
#include <string>

int main()
{
    std::set<std::string> s { "one", "two", "three" };

    if (!s.contains("two"))
        return 1;

    return 0;
}
