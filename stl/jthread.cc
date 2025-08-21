#include <thread>
#include <iostream>


static void thread_func(std::stop_token, int start);


int main()
{
    std::jthread t { thread_func, 55 };

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    t.request_stop();

    return 0;
}


void thread_func(std::stop_token sync, int start)
{
    std::cout << "Starting with: " << start << std::endl;

    while (!sync.stop_requested())
        start++;

    std::cout << "Stopping with: " << start << std::endl;
}
