#include <pthread.h>
#include <iostream>
#include <iomanip>

int main()
{
    pthread_t tid = pthread_self();

    std::cout << tid << std::endl
              << std::hex << tid << std::endl;

    return 0;
}
