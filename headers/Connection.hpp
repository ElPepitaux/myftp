/*
** ETIB PROJECT, 2025
** myftp
** File description:
** Connection
*/

#pragma once

#include <boost/asio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <functional>

#define CRLF "\r\n"

class Connection {
    public:
        Connection(boost::asio::ip::tcp::socket socket);
        ~Connection();

        void setOnMessageReceived(std::function<void(const std::string&)> callback);

        void setOnDisconnected(std::function<void()> callback);

        void write(const std::string &data);

        void read();

        void close();

        bool isAuthenticated() const noexcept;

        void setAuthenticated(bool isAuthenticated) noexcept;

    protected:
        boost::asio::ip::tcp::socket _socket;
        std::vector<char> _readBuffer;

        std::function<void(const std::string&)> _onMessageReceived;
        std::function<void()> _onDisconnected;

        bool _isAuthenticated;

    private:
};

