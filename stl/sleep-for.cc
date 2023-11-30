#include <iostream>
#include <chrono>
#include <thread>
#include <string>


int main(int argc, char *argv[])
{
    using namespace std::chrono_literals;

    auto duration = 2000ms;

    if (argc == 2)
        duration = std::chrono::milliseconds(std::stoi(argv[1]));

    std::cout << "Hello waiter\n" << std::flush;

    const auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(duration);
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Waited " << elapsed.count() << '\n';
}
