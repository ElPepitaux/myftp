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

#define CRLF "\r\n"


class Client {
    public:
        Client(const std::string &host, unsigned short port);
        ~Client();

        void read();

        void write(const std::string &data);

        void close();

        void run();

    protected:
        boost::asio::io_context _ioContext;
        boost::asio::ip::tcp::socket _socket;
        std::thread _thread;
        std::vector<char> _readBuffer;
        bool _isConnected;
    private:
};
