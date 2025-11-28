/*
** ETIB PROJECT, 2025
** myftp
** File description:
** StorHandler
*/

#include "server/commands/StorHandler.hpp"

StorHandler::StorHandler()
{
}

StorHandler::~StorHandler()
{
}

void StorHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    std::string content;
    if (connection.getMode() == Connection::MODE::NONE) {
        connection.write("425 Can't open data connection.\r\n");
        return;
    }
    connection.write("150 File status okay; about to open data connection.\r\n");
    if (connection.getMode() == Connection::MODE::PASSIVE) {
        content = _handlePassiveMode(connection);
    } else if (connection.getMode() == Connection::MODE::ACTIVE) {
        content = _handleActiveMode(connection);
    }
    Utils::writeFileContent(request[1], content);
    connection.write("226 Closing data connection. Requested file action successful.\r\n");
}

std::string StorHandler::_handlePassiveMode(Connection& connection)
{
    // Implementation for handling file storage in passive mode
    return "";
}

std::string StorHandler::_handleActiveMode(Connection& connection)
{
    std::vector<char> fileData;
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket dataSocket(io_context);
    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::make_address(connection.getDataAddress()),
        connection.getDataPort()
    );
    dataSocket.connect(endpoint);
    boost::system::error_code error;
    for (;;) {
        char buffer[1024];
        size_t len = dataSocket.read_some(boost::asio::buffer(buffer), error);
        if (error == boost::asio::error::eof) {
            break; // Connection closed cleanly by peer
        } else if (error) {
            throw boost::system::system_error(error); // Some other error
        }
        fileData.insert(fileData.end(), buffer, buffer + len);
    }
    dataSocket.close();
    return std::string(fileData.begin(), fileData.end());
}
