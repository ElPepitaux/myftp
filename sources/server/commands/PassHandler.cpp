/*
** ETIB PROJECT, 2025
** myftp
** File description:
** PassHandler
*/

#include "server/commands/PassHandler.hpp"

PassHandler::PassHandler()
{
}

PassHandler::~PassHandler()
{
}

void PassHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    // Here we only manage anonymous login
    if (connection.isAuthenticated()) {
        connection.write("230 Already logged in.\r\n");
        return;
    }
    connection.setAuthenticated(true);
    connection.write("230 Login successful.\r\n");
}
