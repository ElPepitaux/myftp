/*
** ETIB PROJECT, 2025
** myftp
** File description:
** DeleHandler
*/

#include "server/commands/DeleHandler.hpp"

DeleHandler::DeleHandler()
{
}

DeleHandler::~DeleHandler()
{
}

void DeleHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    if (std::remove(request[1].c_str()) != 0) {
        connection.write("550 Failed to delete file.\r\n");
        return;
    }
    connection.write("250 File deleted successfully.\r\n");
}
