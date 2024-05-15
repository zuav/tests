//#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <thread>
#include <mutex>

#ifdef ASTRA_LINUX

#include <sys/syscall.h>

inline pid_t gettid() { return syscall(__NR_gettid); }

#endif


std::mutex global_mutex;


void thread_func(int num)
{
    std::lock_guard<std::mutex> lk(global_mutex);

    std::cout << "thread num:                 " << num                        << std::endl
              << "tid():                      " << gettid()                   << std::endl
              << "pthread_self():             " << pthread_self()             << std::endl
              << "std::this_thread::get_id(): " << std::this_thread::get_id() << std::endl
              << std::endl;

    sleep(1);
}


int main()
{
    std::cout << "process id: " << getpid() << std::endl
              << std::endl;

    global_mutex.lock();

    std::thread t1(thread_func, 1);
    std::thread t2(thread_func, 2);
    std::thread t3(thread_func, 3);

    std::cout << "t1.get_id():        " << t1.get_id() << std::endl
              << "t1.native_handle(): " << t1.native_handle() << std::endl
              << std::endl
              << "t2.get_id():        " << t2.get_id() << std::endl
              << "t2.native_handle(): " << t2.native_handle() << std::endl
              << std::endl
              << "t3.get_id():        " << t3.get_id() << std::endl
              << "t3.native_handle(): " << t3.native_handle() << std::endl
              << std::endl;
    global_mutex.unlock();

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
