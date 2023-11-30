#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <iostream>


static void thread_func();
static void signal_handler(int);


int main()
{
    struct sigaction action;
    action.sa_handler = signal_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    int rc = sigaction(SIGUSR1, &action, NULL);
    if (rc != 0) {
        std::cerr << "failed to set signal handler for SIGINT" << strerror(rc);
        return 1;
    }

    using namespace std::chrono_literals;

    std::thread t(thread_func);
    std::this_thread::sleep_for(2s);
    pthread_kill(t.native_handle(), SIGUSR1);
    t.join();

    return 0;
}


void thread_func()
{
    using namespace std::chrono_literals;

    const auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(5s);
    // sleep(5);
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = end - start;

    std::cout << "Waited " << elapsed.count() << '\n';
}


void signal_handler(int)
{
}
