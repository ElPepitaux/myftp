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
    Connection(boost::asio::io_context& io_context, boost::asio::ip::tcp::socket socket);

    ~Connection();

    enum class MODE {
        ACTIVE,
        PASSIVE,
        NONE
    };

    void write(const std::string &data);
    void read();
    void close();
    void setPasvEndpoint(const boost::asio::ip::tcp::endpoint& ep) noexcept;
    const boost::asio::ip::tcp::endpoint& getPasvEndpoint() const noexcept;

    void setOnMessageReceived(std::function<void(const std::string&)> callback);
    void setOnDisconnected(std::function<void()> callback);

    bool isAuthenticated() const noexcept;
    void setAuthenticated(bool isAuthenticated) noexcept;

    MODE getMode() const noexcept;
    void setMode(MODE mode) noexcept;

    void setDataAddress(const std::string& address) noexcept;
    void setDataPort(uint16_t port) noexcept;

    const std::string& getDataAddress() const noexcept;
    uint16_t getDataPort() const noexcept;

    boost::asio::ip::tcp::acceptor& getDataAcceptor() noexcept;
    void setDataAcceptor(boost::asio::ip::tcp::acceptor acceptor) noexcept;
    bool hasDataAcceptor() const noexcept;

private:
    void init();

private:
    boost::asio::ip::tcp::endpoint _pasvEndpoint; 
    boost::asio::io_context& _io_context;
    boost::asio::ip::tcp::socket _socket;
    boost::asio::ip::tcp::acceptor _dataAcceptor;

    std::vector<char> _readBuffer;

    std::function<void(const std::string&)> _onMessageReceived;
    std::function<void()> _onDisconnected;

    bool _isAuthenticated;
    MODE _mode;

    std::string _dataAddress;
    uint16_t _dataPort;
};
