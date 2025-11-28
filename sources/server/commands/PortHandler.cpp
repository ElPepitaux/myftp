/*
** ETIB PROJECT, 2025
** myftp
** File description:
** PortHandler
*/

#include "server/commands/PortHandler.hpp"

PortHandler::PortHandler()
{
}

PortHandler::~PortHandler()
{
}

void PortHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    std::vector<std::string> addressParts = Utils::splitString(request[1], ',');
    if (addressParts.size() != 6) {
        connection.write("501 Syntax error in parameters or arguments." CRLF);
        return;
    }
    connection.setMode(Connection::MODE::ACTIVE);
    std::string ipAddress = addressParts[0] + "." + addressParts[1] + "." + addressParts[2] + "." + addressParts[3];
    uint16_t port = std::stoi(addressParts[4]) * 256 + std::stoi(addressParts[5]);
    connection.setDataAddress(ipAddress);
    connection.setDataPort(port);
    connection.write("200 PORT command successful." CRLF);
}
