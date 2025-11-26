/*
** ETIB PROJECT, 2025
** myftp
** File description:
** UserHandler
*/

#include "server/commands/UserHandler.hpp"

UserHandler::UserHandler()
{
}

UserHandler::~UserHandler()
{
}

void UserHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    if (request[1] != "anonymous") {
        throw ExceptionHandler("Only anonymous users are allowed.", 530);
    }
    connection.setAuthenticated(true);
    connection.write("230 User logged in, proceed.\r\n");
}
