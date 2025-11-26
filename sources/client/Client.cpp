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
        _connection = std::make_shared<Connection>(std::move(_socket));

        _connection->setOnMessageReceived(
            [](const std::string &message) {
                std::cout << message;
            }
        );
        _connection->setOnDisconnected(
            [this]() {
                std::cout << "Disconnected from server." <<  std::endl;
                _isConnected = false;
            }
        );
        _connection->read();

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

void Client::close()
{
    _isConnected = false;
    _connection->close();
    if (_thread.joinable())
        _thread.join();
}

void Client::run()
{
    while (_isConnected) {
        std::string input;
        std::getline(std::cin, input);
        if (input == "exit") {
            close();
            break;
        }
        input += CRLF;
        _connection->write(input);
    }
}
