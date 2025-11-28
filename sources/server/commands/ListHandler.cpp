/*
** ETIB PROJECT, 2025
** myftp
** File description:
** ListHandler
*/

#include "server/commands/ListHandler.hpp"

ListHandler::ListHandler()
{
}

ListHandler::~ListHandler()
{
}

void ListHandler::handle(const std::vector<std::string>& request, Connection& connection)
{
    std::string path = ".";

    if (request.size() > 1) {
        path = request[1];
    }
    std::string listing = _listDirectoryContent(path);

    if (listing.empty()) {
        throw ExceptionHandler("Failed to list directory.", 550);
    }
    connection.write("150 Here comes the directory listing for \"" + path + "\".\r\n");
    if (connection.getMode() == Connection::MODE::ACTIVE) {
        _sendPortMode(connection, listing);
    } else {
        _sendPassiveMode(connection, listing);
    }
    connection.write("226 Directory send OK.\r\n");
}

std::string ListHandler::_listDirectoryContent(const std::string& path)
{
    std::string result = "";

    if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path)) {
        throw ExceptionHandler("Directory does not exist.", 550);
    }

    std::string output;
    char* argv[] = {const_cast<char*>("-l"), const_cast<char*>(path.c_str()), nullptr};

    if (fork() == 0) {
        // Child process
        dup2(fileno(stdout), STDOUT_FILENO);
        execve("/bin/ls", argv, nullptr);
        exit(1); // execve only returns on error
    } else {
        // Parent process
        FILE* pipe = popen("/bin/ls -l", "r");
        if (!pipe) {
            throw ExceptionHandler("Failed to open pipe for listing.", 550);
        }
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
        pclose(pipe);
    }
    return result;
}

void ListHandler::_sendPortMode(Connection& connection, const std::string& message)
{
    try {
        boost::asio::io_context io_context;
        boost::asio::ip::tcp::socket dataSocket(io_context);
        boost::asio::ip::tcp::endpoint endpoint(
            boost::asio::ip::make_address(connection.getDataAddress()),
            connection.getDataPort()
        );
        dataSocket.connect(endpoint);
        boost::asio::write(dataSocket, boost::asio::buffer(message));
        dataSocket.close();
    } catch (const std::exception& e) {
        throw ExceptionHandler("Failed to send data in PORT mode: " + std::string(e.what()), 550);
    }
}

void ListHandler::_sendPassiveMode(Connection& connection, const std::string& message)
{
    // Implementation for sending data in PASSIVE mode
}
