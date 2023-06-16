#include <string.h>
#include <map>
#include <iostream>
#include <iomanip>
#include <string>


struct Digit {
    const char *val;
    int len;

    explicit Digit(const char *v) : val(v), len(strlen(val)) {}
};

std::ostream& operator<<(std::ostream& os, const Digit& d)
{
    return os << '(' << std::setw(3) << d.val << ',' << d.len << ')';
}


std::map<int, Digit>  digits_table {
    { 0,   Digit("0")   },
    { 15,  Digit("15")  },
    { 123, Digit("123") }
};


int main(int argc, char *argv[])
{
    for (const auto& [key, value] : digits_table)
        std::cout << std::setw(3) << key << " --> " << value << std::endl;

    return 0;
}
