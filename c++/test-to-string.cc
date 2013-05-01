//#include "common.h"

#include <iostream>
#include <string>

#define TEST_RESULT(type, got, exp)                    \
    if (got != exp) {                                  \
        std::cout << "to_string(##type) failed: got: " \
                  << got                               \
                  << "; expected: "                    \
                  << exp                               \
                  << std::endl;                        \
        return 1;                                      \
    };


int test_to_string()
{
    std::string s1 = std::to_string(int(33));
    std::string s1_exp = "33";
    TEST_RESULT(int, s1, s1_exp);

    // if (s1 != s1_exp) {
    //     std::cout << "to_string(int) failed: got: " << s1 << "; expected: " << s1_exp << std::endl;
    //     return 1;
    // }

    // std::string s2 = std::to_string(long(2105238571));
    // std::string s2_exp = "2105238571";
    // if (s2 != s2_exp) {
    //     std::cout << "to_string(long) failed: got: " << s2 << "; expected: " << s2_exp << std::endl;
    //     return 1;
    // }

    // std::string s3 = std::to_string( long long value );
    // std::string to_string( unsigned value );
    // std::string to_string( unsigned long value );
    // std::string to_string( unsigned long long value );
    // std::string to_string( float value );
    // std::string to_string( double value );
    // std::string to_string( long double value );

    return 0;
}

int main()
{
    int v = test_to_string();

    return v;
}
