/*
** ETIB PROJECT, 2025
** myftp
** File description:
** Connection
*/

#include "server/Connection.hpp"

Connection::Connection(boost::asio::ip::tcp::socket socket)
    : _socket(std::move(socket))
{
    _readBuffer.resize(1024);
}

Connection::~Connection()
{
    _socket.close();
}

void Connection::write(const std::string &data)
{
    boost::asio::write(_socket, boost::asio::buffer(data));
}

void Connection::read()
{
    _socket.async_receive(boost::asio::buffer(_readBuffer),
        [this](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::string data(_readBuffer.data(), length);
                std::cout << "Received data: " << data << std::endl;
                read();
            } else {
                std::cerr << "Client disconnected: " << ec.message() << std::endl;
            }
        }
    );
}
