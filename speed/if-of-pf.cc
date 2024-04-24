#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <functional>
#include <atomic>
#include <chrono>


using Pf_write = ssize_t (*)(int, const void *, size_t);
using Pf_stdfunc = std::function<ssize_t(int, const void *, size_t)>;


constexpr int BUF_SIZE = 0;


static void do_work_clean    (int handle, int num);
static void do_work_if       (int handle, int num);
static void do_work_if_atomic(int handle, int num);
static void do_work_pf       (int handle, int num, Pf_write);
static void do_work_pf_atomic(int handle, int num, Pf_write);
static void do_work_std_func (int handle, int num, Pf_stdfunc);



int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << program_invocation_short_name << " number" << std::endl;
        return 1;
    }

    int num = strtol(argv[1], 0, 0);
    std::cout << "number: " << num << std::endl;

    const char *fname = "/dev/null";
    int handle = open(fname, O_SYNC|O_WRONLY);
    if (handle == -1) {
        std::cerr << "failed to open " << fname << ": " << errno << ": " << strerror(errno) << std::endl;
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();
    do_work_clean(handle, num);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds diff0 = end - start;
    std::cout << "clean:     " << diff0.count() << ", " << 0 << std::endl;

    start = std::chrono::high_resolution_clock::now();
    do_work_if(handle, num);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds diff = end - start;
    std::cout << "if:        " << diff.count() << ", " << double(diff.count() - diff0.count())/num << std::endl;

    start = std::chrono::high_resolution_clock::now();
    do_work_if_atomic(handle, num);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "if atomic: " << diff.count() << ", " << double(diff.count() - diff0.count())/num << std::endl;

    start = std::chrono::high_resolution_clock::now();
    do_work_pf(handle, num, write);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "pf:        " << diff.count() << ", " << double(diff.count() - diff0.count())/num << std::endl;

    start = std::chrono::high_resolution_clock::now();
    do_work_pf_atomic(handle, num, write);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "pf atomic: " << diff.count() << ", " << double(diff.count() - diff0.count())/num << std::endl;

    start = std::chrono::high_resolution_clock::now();
    do_work_std_func(handle, num, write);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "std func:  " << diff.count() << ", " << double(diff.count() - diff0.count())/num << std::endl;

    return 0;
}


void do_work_clean(int handle, int num)
{
    char buf[BUF_SIZE];

    for (int i=0; i<num; ++i) {
        if (write(handle, buf, sizeof(buf)) == -1) {
            std::cerr << "clean write failed: " << errno << ": " << strerror(errno) << std::endl;
            exit(1);
        }
    }
}


void do_work_if(int handle, int num)
{
    char buf[BUF_SIZE];

    for (int i=0; i<num; ++i) {
        if (handle != -1) {
            if (write(handle, buf, sizeof(buf)) == -1) {
                std::cerr << "if write failed: " << errno << ": " << strerror(errno) << std::endl;
                exit(1);
            }
        }
    }
}


void do_work_if_atomic(int handle, int num)
{
    char buf[BUF_SIZE];
    std::atomic<int> h = handle;

    for (int i=0; i<num; ++i) {
        if (h != -1) {
            if (write(handle, buf, sizeof(buf)) == -1) {
                std::cerr << "if write failed: " << errno << ": " << strerror(errno) << std::endl;
                exit(1);
            }
        }
    }
}


void do_work_pf(int handle, int num, Pf_write pfwrite)
{
    char buf[BUF_SIZE];

    for (int i=0; i<num; ++i) {
        // if (pfwrite(handle, buf, sizeof(buf)) == -1) {
        if (pfwrite(handle, buf, sizeof(buf)) == -1) {
            std::cerr << "pf write failed: " << errno << ": " << strerror(errno) << std::endl;
            exit(1);
        }
    }
}


void do_work_pf_atomic(int handle, int num, Pf_write pfwrite)
{
    char buf[BUF_SIZE];

    std::atomic<Pf_write> pf_atomic_write = pfwrite;

    for (int i=0; i<num; ++i) {
        // if (pfwrite(handle, buf, sizeof(buf)) == -1) {
        if (pf_atomic_write(handle, buf, sizeof(buf)) == -1) {
            std::cerr << "pf write failed: " << errno << ": " << strerror(errno) << std::endl;
            exit(1);
        }
    }
}


void do_work_std_func(int handle, int num, Pf_stdfunc pfwrite)
{
    char buf[BUF_SIZE];

    for (int i=0; i<num; ++i) {
        if (pfwrite(handle, buf, sizeof(buf)) == -1) {
            std::cerr << "pf write failed: " << errno << ": " << strerror(errno) << std::endl;
            exit(1);
        }
    }
}
