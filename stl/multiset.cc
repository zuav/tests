#include <iostream>
#include <set>
#include <string>


struct Record {
    std::string str;
    int num;

    bool operator<(const Record& r) const { return num < r.num; }
};

std::ostream& operator<<(std::ostream&, const Record&);


int main(int, char *[])
{
    std::multiset<Record> table { { "a1", 1 }, { "a4", 4 }, { "a3", 3 }, { "a2", 2 }, { "b2", 2 } };

    for (const auto& v : table)
        std::cout << v << ' ';
    std::cout << std::endl;

    std::cout << "begin 1: " << *(table.begin()) << std::endl;

    auto pos = table.begin();
    Record r = *pos;
    table.erase(pos);
    r.num += 9;
    table.insert(r);

    for (const auto& v : table)
        std::cout << v << ' ';
    std::cout << std::endl;

    std::cout << "begin 2: " << *(table.begin()) << std::endl;


    return 0;
}


std::ostream& operator<<(std::ostream& os, const Record& r)
{
    return os << "(" << r.str << "," << r.num << ")";
}
