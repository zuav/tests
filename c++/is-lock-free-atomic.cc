#include <atomic>
#include <iostream>

int main()
{
    std::atomic_bool b;
    std::atomic_int  i;

    std::cout << std::boolalpha
              << "std::atomic_bool::is_lock_free: " << b.is_lock_free() << std::endl
              << "std::atomic_int::is_lock_free:  " << i.is_lock_free() << std::endl;

    return 0;
}
