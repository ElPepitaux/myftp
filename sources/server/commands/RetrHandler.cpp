/*
** ETIB PROJECT, 2025
** myftp
** File description:
** RetrHandler
*/

#include "server/commands/RetrHandler.hpp"

RetrHandler::RetrHandler()
{
}

RetrHandler::~RetrHandler()
{
}

void RetrHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    std::string fileContent;
    if (connection.getMode() == Connection::MODE::NONE) {
        connection.write("425 Can't open data connection.\r\n");
        return;
    }
    connection.write("150 File status okay; about to open data connection.\r\n");
    if (connection.getMode() == Connection::MODE::PASSIVE) {
        fileContent = _handlePassiveMode(connection, request[1]);
    } else if (connection.getMode() == Connection::MODE::ACTIVE) {
        fileContent = _handleActiveMode(connection, request[1]);
    }
    Utils::writeFileContent(request[1], fileContent);
    connection.write("226 Closing data connection. Requested file action successful.\r\n");
}

std::string RetrHandler::_handlePassiveMode(Connection& connection, const std::string& filename)
{
    std::string fileContent;
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket dataSocket(io_context);
    boost::system::error_code error;
    boost::system::error_code acceptError;
    connection.getDataAcceptor().accept(dataSocket, acceptError);
    if (acceptError) {
        throw boost::system::system_error(acceptError);
    }
    std::vector<char> buffer(1024);
    for (;;) {
        size_t len = dataSocket.read_some(boost::asio::buffer(buffer), error);
        if (error == boost::asio::error::eof) {
            break; // Connection closed cleanly by peer
        } else if (error) {
            throw boost::system::system_error(error); // Some other error
        }
        if (len == 0) {
            break; // No more data
        }
        fileContent.append(buffer.data(), len);
    }
    boost::system::error_code shutdownErr;
    dataSocket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, shutdownErr);
    dataSocket.close();
    return fileContent;
}

std::string RetrHandler::_handleActiveMode(Connection& connection, const std::string& filename)
{
    std::string fileContent;
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket dataSocket(io_context);
    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::make_address(connection.getDataAddress()),
        connection.getDataPort()
    );
    dataSocket.connect(endpoint);
    boost::system::error_code error;
    std::vector<char> buffer(1024);
    for (;;) {
        size_t len = dataSocket.read_some(boost::asio::buffer(buffer), error);
        if (error == boost::asio::error::eof) {
            break; // Connection closed cleanly by peer
        } else if (error) {
            throw boost::system::system_error(error); // Some other error
        }
        fileContent.append(buffer.data(), len);
    }
    return fileContent;
}
