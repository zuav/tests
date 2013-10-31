#include <atomic>
#include <iostream>

int main()
{
    std::atomic_int i;

    std::cout << "std::atomic_int is " << (i.is_lock_free() ? "lock free" : "NOT lock free.") << std::endl;

    return 0;
}
