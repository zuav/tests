#include <stdint.h>
#include <pthread.h>
#include <iostream>
#include <iomanip>

int main()
{
    pthread_t tid = pthread_self();

    std::cout << tid << std::endl
              << std::hex << tid << std::endl
              << std::setw(16) << std::setfill('0') << std::hex << uint64_t(tid) << std::endl;

    return 0;
}
