/*
** ETIB PROJECT, 2025
** myftp
** File description:
** CwdHandler
*/

#include "server/commands/CwdHandler.hpp"

CwdHandler::CwdHandler()
{
}

CwdHandler::~CwdHandler()
{
}

void CwdHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    if (request.size() < 2) {
        throw ExceptionHandler("CWD command requires a directory argument.", 501);
    }

    std::string directory = request[1];
    if (chdir(directory.c_str()) != 0) {
        throw ExceptionHandler("Failed to change directory.", 550);
    }

    connection.write("250 Directory successfully changed.\r\n");
}
