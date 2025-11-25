/*
** ETIB PROJECT, 2025
** myftp
** File description:
** server
*/

#include "server/Server.hpp"

Server::Server(unsigned short port)
    : _acceptor(_ioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
    _isRunning = true;
    startAccept();
    _thread = std::thread([this]() { _ioContext.run(); });
    std::cout << "Server started on port " << port << std::endl;
}

Server::~Server()
{
    stop();
}

void Server::startAccept()
{
    _acceptor.async_accept(
        [this](const boost::system::error_code &error,
               boost::asio::ip::tcp::socket socket) {
            handleAccept(error, std::move(socket));
        });
}

void Server::handleAccept(const boost::system::error_code &error,
                          boost::asio::ip::tcp::socket socket)
{
    if (!error) {
        auto connection = std::make_shared<Connection>(std::move(socket));
        connection->read();
        _connections.push_back(connection);
        std::cout << "New connection accepted." << std::endl;
    } else {
        std::cerr << "Error accepting connection: " << error.message() << std::endl;
    }
    startAccept();
}

void Server::stop()
{
    _ioContext.stop();
    if (_thread.joinable())
        _thread.join();
}

void Server::run()
{
    std::cout << "Server is running..." << std::endl;
    while (_isRunning) {
        // Server main loop can be implemented here
    }
}
