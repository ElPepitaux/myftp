/*
** ETIB PROJECT, 2025
** myftp
** File description:
** QuitHandler
*/

#include "server/commands/QuitHandler.hpp"

QuitHandler::QuitHandler()
{
}

QuitHandler::~QuitHandler()
{
}

void QuitHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    connection.write("221 Goodbye.\r\n");
    connection.setAuthenticated(false);
    connection.close();
}
