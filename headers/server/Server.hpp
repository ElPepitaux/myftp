/*
** ETIB PROJECT, 2025
** myftp
** File description:
** Server
*/

#pragma once

#include <boost/asio.hpp>
#include <thread>
#include <list>
#include <memory>

#include "Utils.hpp"
#include "Connection.hpp"
#include "server/ServerChainResponsibility.hpp"

class Server {
    public:
        Server(unsigned short port);
        ~Server();

        void run();

        void stop();

        void startAccept();

        void handleAccept(const boost::system::error_code &error,
                          boost::asio::ip::tcp::socket socket);

    protected:
        boost::asio::io_context _ioContext;
        boost::asio::ip::tcp::acceptor _acceptor;
        std::thread _thread;
        bool _isRunning;

        std::list<std::shared_ptr<Connection>> _connections;
        std::shared_ptr<ServerChainResponsibility> _chainResponsibility;

    private:
};

