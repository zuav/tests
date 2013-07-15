// try to compile as:
//
// c++ -DVAR=ONE defines.cc
//

#include <iostream>

#define ONE 1
#define TWO 2


int main()
{
    std::cout << "VAR = " << VAR << std::endl;

    return 0;
}
