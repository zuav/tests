#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>
#include <boost/asio.hpp>


std::array<char, 100> read_buffer;

bool stopped_flag = false;
std::mutex stopped_mutex;
std::condition_variable stopped_condvar;

boost::asio::io_service io_service;
boost::asio::ip::tcp::socket tcp_socket { io_service };


void handle_read(const boost::system::error_code& ec, size_t bytes);
void network_thread_func();


int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cout << "Usage: asio-tcp-read-async-some ip port" << std::endl;
        return 1;
    }

    std::string ip = argv[1];
    std::string port = argv[2];

    std::cout << "address: " << ip << ':' << port << std::endl;

    boost::asio::ip::tcp::endpoint endpoint;
    endpoint.address(boost::asio::ip::make_address(ip));
    endpoint.port(std::stoi(port));

    boost::system::error_code ec;
    tcp_socket.connect(endpoint, ec);
    if (ec) {
        std::cerr << "connect failed with error: " << ec.message() << std::endl;
        return 1;
    }
    std::cout << "connected to: " << ip << ':' << port << std::endl;

    auto start = std::chrono::steady_clock::now();

    const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    const time_t tm = std::chrono::system_clock::to_time_t(now);
    std::cout << "start reading at: " << std::put_time(localtime(&tm), "%F %T") << std::endl;

    tcp_socket.async_read_some(boost::asio::buffer(read_buffer, read_buffer.size()), handle_read);

    std::thread thread { network_thread_func };
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::unique_lock lk(stopped_mutex);
    stopped_condvar.wait(lk, [] { return stopped_flag; });

    auto stop = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = stop - start;

    std::cout << "time passed: " << diff.count() << "s" << std::endl;

    io_service.stop();
    thread.join();

    return 0;
}


void handle_read(const boost::system::error_code& ec, size_t bytes)
{
    if (ec) {
        std::cerr << "read failed with error: " << ec.message() << std::endl;
        std::unique_lock lk(stopped_mutex);
        stopped_flag = true;
        lk.unlock();
        stopped_condvar.notify_one();
        return;
    }

    std::cout << "read " << bytes << ": " << std::string(read_buffer.data(), bytes) << std::endl;

    tcp_socket.async_read_some(boost::asio::buffer(read_buffer, read_buffer.size()), handle_read);
}


void network_thread_func()
{
    std::cout << "network thread started" << std::endl;

    try {
        io_service.run();
    } catch (std::exception& exc) {
        std::cerr << "io_service::run terminated with exception: " << exc.what() << std::endl;
    } catch (...) {
        std::cerr << "io_service::run terminated with unknown exception" << std::endl;
    }

    std::cout << "network thread stopped" << std::endl;
}
