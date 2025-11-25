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

class Connection {
    public:
        Connection(boost::asio::ip::tcp::socket socket);
        ~Connection();

        void write(const std::string &data);

        void read();

        void close();

    protected:
        boost::asio::ip::tcp::socket _socket;
        std::vector<char> _readBuffer;
        
    private:
};

