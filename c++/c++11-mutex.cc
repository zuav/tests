#include <iostream>
#include <mutex>

int main()
{
    std::mutex m;
    std::lock_guard<std::mutex> lock(m);

    std::cout << "mutex locked" << std::endl;

    m.unlock();

    return 0;
}
