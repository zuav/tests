#include <stdint.h>
#include <array>
#include <string>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

constexpr int BUF_SIZE = 2;

class udp_server {
public:
    udp_server(boost::asio::io_context& io_context, int port);

private:
    void start_receive();
    void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);
    // void handle_send(const boost::system::error_code& error, std::size_t bytes_transferred);

  udp::socket socket;
  udp::endpoint remote_endpoint;
  std::array<int8_t, BUF_SIZE> recv_buffer;
};



int main(int argc, char *argv[])
{
    int port = 20000;
    if (argc == 2)
        port = std::stoi(argv[1]);

    try {
        boost::asio::io_context io_context;
        udp_server server(io_context, port);
        io_context.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


udp_server::udp_server(boost::asio::io_context& io_context, int port)
    : socket(io_context, udp::endpoint(udp::v4(), port))
{
    std::cout << "starting UDP server on port: " << port << "; buf size: " << BUF_SIZE << std::endl;

    start_receive();
}


void udp_server::start_receive()
{
    socket.async_receive_from(boost::asio::buffer(recv_buffer),
                              remote_endpoint,
                              boost::bind(&udp_server::handle_receive,
                                          this,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred));
}


void udp_server::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    if (!error) {
        std::cout << "number of bytes received: " << bytes_transferred << std::endl;

        start_receive();
    } else {
        std::cout << "error receiving packet: " << error << std::endl;
    }
}


// void udp_server::handle_send(const boost::system::error_code& error, std::size_t bytes_transferred)
// {
// }



// #include <ctime>
// #include <iostream>
// #include <string>
// #include <boost/array.hpp>
// #include <boost/shared_ptr.hpp>
