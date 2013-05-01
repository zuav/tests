#include <string>
#include <iostream>

int main()
{
    long double v9 = 1965.0508;
    std::string s9 = std::to_string(v9);
    std::string s9exp = "1965.050800";
    if (s9 != s9exp) {
        std::cout << "to_string(long double) failed: "
                  << "got: " << s9 << "; expected: " << s9exp
                  << std::endl;
        return 1;
    }

    return 0;
}
