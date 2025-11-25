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

void Connection::setOnMessageReceived(std::function<void(const std::string&)> callback)
{
    _onMessageReceived = callback;
}

void Connection::setOnDisconnected(std::function<void()> callback)
{
    _onDisconnected = callback;
}

void Connection::read()
{
    _socket.async_receive(boost::asio::buffer(_readBuffer),
        [this](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::string data(_readBuffer.data(), _readBuffer.data() + length);

                do {
                int pos = data.find(CRLF);
                if (pos == std::string::npos)
                    break;
                _onMessageReceived(data);
                data = data.substr(pos + 2);
                } while (true);
                read();
            } else {
                _onDisconnected();
            }
        }
    );
}
