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

        enum class MODE {
            ACTIVE,
            PASSIVE,
            NONE
        };

        void setOnMessageReceived(std::function<void(const std::string&)> callback);

        void setOnDisconnected(std::function<void()> callback);

        void write(const std::string &data);

        void read();

        void close();

        bool isAuthenticated() const noexcept;

        void setAuthenticated(bool isAuthenticated) noexcept;

        MODE getMode() const noexcept;

        void setMode(MODE mode) noexcept;

        void setDataAddress(const std::string& address) noexcept;

        void setDataPort(uint16_t port) noexcept;

        const std::string& getDataAddress() const noexcept;

        uint16_t getDataPort() const noexcept;

    protected:
        boost::asio::ip::tcp::socket _socket;
        std::vector<char> _readBuffer;

        std::function<void(const std::string&)> _onMessageReceived;
        std::function<void()> _onDisconnected;

        bool _isAuthenticated;
        MODE _mode;

        std::string _dataAddress;
        uint16_t _dataPort;

    private:
};

