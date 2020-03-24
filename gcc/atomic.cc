#include <iostream>


int main()
{
    bool b = true;
    bool v = false;

    __atomic_load(&b, &v, __ATOMIC_RELAXED);
    std::cout << "true:  v = " << v << std::endl;

    b = false;
    __atomic_store(&v, &b, __ATOMIC_RELAXED);
    std::cout << "false: v = " << v << std::endl;

    bool lf = __atomic_always_lock_free(sizeof(bool), &b);
    std::cout << "bool is lock free: " << lf << std::endl;

    return 0;
}
