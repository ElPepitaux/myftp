/*
** ETIB PROJECT, 2025
** myftp
** File description:
** HelpHandler
*/

#include "server/commands/HelpHandler.hpp"

HelpHandler::HelpHandler()
{
}

HelpHandler::~HelpHandler()
{
}

void HelpHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    std::string fullHelpMessage =
        "214-The following commands are recognized:\n"
        " USER <username> - Login (anonymous only here)\n"
        " PASS <password> - Password (any password accepted for anonymous)\n"
        " PASV - Enter passive mode\n"
        " PORT <host> - Enter active mode\n"
        " LIST [directory] - List files in the current directory\n"
        " RETR <filename> - Retrieve (download) a file\n"
        " STOR <filename> - Store (upload) a file\n"
        " DELE <filename> - Delete a file\n"
        " CWD <directory> - Change working directory\n"
        " HELP - Show this help message\n"
        " QUIT - Disconnect from the server\n"
        "214 Help OK.\r\n";
    std::string preLoginMessage =
        "214-The following commands are recognized:\n"
        " USER <username> - Login (anonymous only here)\n"
        " PASS <password> - Password (any password accepted for anonymous)\n"
        " HELP - Show this help message\n"
        " QUIT - Disconnect from the server\n"
        "214 Help OK.\r\n";

    if (!connection.isAuthenticated()) {
        connection.write(preLoginMessage);
        return;
    }
    connection.write(fullHelpMessage);
}
