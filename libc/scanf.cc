#include <stdio.h>
#include <iostream>

int main()
{
    int number = 0;
//     char buf[2] = { 0, 0 };

//     int numread = scanf("version%1s%d", buf, &number);
    int numread = scanf("version.*:%d", &number);

    std::cout << "numread: " << numread << std::endl
//               << "buf:     " << buf << std::endl
              << "number:  " << number << std::endl;

    return 0;
}
