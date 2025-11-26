/*
** ETIB PROJECT, 2025
** myftp
** File description:
** Client
*/

#pragma once

#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include <string>
#include <iostream>

#include "Connection.hpp"

#define CRLF "\r\n"

class Client {
    public:
        Client(const std::string &host, unsigned short port);
        ~Client();


        void close();

        void run();

    protected:
        boost::asio::io_context _ioContext;
        boost::asio::ip::tcp::socket _socket;
        std::thread _thread;
        std::vector<char> _readBuffer;
        bool _isConnected;

        std::shared_ptr<Connection> _connection;
    private:
};
