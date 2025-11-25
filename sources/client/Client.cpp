/*
** ETIB PROJECT, 2025
** myftp
** File description:
** client
*/

#include "client/Client.hpp"

Client::Client(const std::string &host, unsigned short port)
    : _socket(boost::asio::ip::tcp::socket(_ioContext))
{
    try {
        std::cout << "Connecting to " << host << ":" << port << "..." << std::endl;
        _isConnected = false;
        boost::asio::ip::tcp::resolver resolver(_ioContext);
        auto endpoints = resolver.resolve(host, std::to_string(port));
        boost::asio::connect(_socket, endpoints);
        _isConnected = true;

        std::cout << "Connected to " << host << ":" << port << std::endl;
        _readBuffer.resize(1024);
        read();

        _thread = std::thread([this]() {
            _ioContext.run();
        });

    } catch (const std::exception &e) {
        _isConnected = false;
    }
}

Client::~Client()
{
    _socket.close();
}

void Client::read()
{
    _socket.async_receive(boost::asio::buffer(_readBuffer),
        [this](const boost::system::error_code &error, std::size_t bytes_transferred) {
            if (!error) {
                std::string data(_readBuffer.data(), bytes_transferred);
                std::cout << "Received: " << data << std::endl;
            }
            read();
        });
}

void Client::write(const std::string &data)
{
    if (!_isConnected)
        return;

    boost::asio::async_write(_socket, boost::asio::buffer(data),
        [this](const boost::system::error_code &error, std::size_t /*bytes_transferred*/) {
            if (error) {
                std::cerr << "Error on write: " << error.message() << std::endl;
            }
        });
}

void Client::close()
{
    _isConnected = false;
    _socket.close();
    if (_thread.joinable())
        _thread.join();
}

void Client::run()
{
    while (_isConnected) {
        std::string input;
        std::getline(std::cin, input);
        std::cout << "Sending: " << input << std::endl;
        if (input == "exit") {
            close();
            break;
        }
        write(input);
    }
}
