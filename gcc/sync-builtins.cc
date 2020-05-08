#include <iostream>


int main()
{
    bool member = false;
    bool newvalue = true;

    __sync_val_compare_and_swap(&member, member, newvalue);
    std::cout << "true:  member = " << member << std::endl;

    return 0;
}
