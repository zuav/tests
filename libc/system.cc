#include "stdlib.h"
#include <iostream>
#include <string>


int main()
{
    std::string cmd = "systemctl --user list-units --all 'vsigw*' > system-result.txt";
    int rc = system(cmd.c_str());

    std::cout << "system retuned code: " << rc << std::endl;

    return 0;
}
