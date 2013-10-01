//

#include <iostream>


#define DEBUG_PROGRAM


#ifdef DEBUG_PROGRAM
#define DEBUG_FUN_0()    std::cout << "debug" << std::endl;
#define DEBUG_FUN_1(c)   std::cout << "debug value: " << c << std::endl;
#else
#define DEBUG_FUN_0()
#define DEBUG_FUN_1(c)
#endif


int main()
{
    DEBUG_FUN_0();
    DEBUG_FUN_1(1);

    return 0;
}
