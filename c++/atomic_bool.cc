#include <atomic>
#include <iostream>

int main()
{
    bool v = true;
    std::atomic_bool f(v);

    std::cout << "atomic_bool is lock free: " << f.is_lock_free() << std::endl;

    std::cout << "flag value: ";
    if (f.load())
        std::cout << "true\n";
    else
        std::cout << "false\n";
        

    v = false;
    f.store(v);
    std::cout << "flag value: ";
    if (f.load())
        std::cout << "true\n";
    else
        std::cout << "false\n";

    return 0;
}
