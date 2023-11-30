#include <time.h>
#include <iostream>
#include <chrono>


int main()
{
    using namespace std::chrono;

    steady_clock::time_point now = steady_clock::now();

    const time_t t = std::chrono::steady_clock::to_time_t(now);
    std::cout << std::put_time(localtime(&t), "%F %T.\n") << std::end;

    return 0;
}
