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
    if (connection.getMode() == Connection::MODE::NONE) {
        connection.write("425 Can't open data connection.\r\n");
        return;
    }
    connection.write("150 File status okay; about to open data connection.\r\n");
    if (connection.getMode() == Connection::MODE::PASSIVE) {
        _handlePassiveMode(connection, request[1]);
    } else if (connection.getMode() == Connection::MODE::ACTIVE) {
        _handleActiveMode(connection, request[1]);
    }
    connection.write("226 Closing data connection. Requested file action successful.\r\n");
}

void RetrHandler::_handlePassiveMode(Connection& connection, const std::string& filename)
{
}

void RetrHandler::_handleActiveMode(Connection& connection, const std::string& filename)
{
    std::string fileContent = Utils::getFileContent(filename);
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket dataSocket(io_context);
    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::make_address(connection.getDataAddress()),
        connection.getDataPort()
    );
    dataSocket.connect(endpoint);
    boost::system::error_code error;
    boost::asio::write(dataSocket, boost::asio::buffer(fileContent), error);
    if (error) {
        throw boost::system::system_error(error);
    }
    dataSocket.close();
}
