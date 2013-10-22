#include <stdint.h>
#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <iomanip>

int main()
{
    pthread_t tid = pthread_self();

    std::cout << tid << std::endl
              << std::hex << tid << std::endl
              << std::setw(16) << std::setfill('0') << std::hex << uint64_t(tid) << std::endl;

    printf("[%016llx]\n", uint64_t(tid));

    return 0;
}
