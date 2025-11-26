/*
** ETIB PROJECT, 2025
** myftp
** File description:
** ChainResponsibility
*/

#include "ChainResponsibility.hpp"

ChainResponsibility::ChainResponsibility()
{
}

ChainResponsibility::~ChainResponsibility()
{
}

void ChainResponsibility::handleRequest(const std::string& route, const std::string& request, Connection& connection)
{
    try {
        auto it = _routes.find(route);
        if (it != _routes.end()) {
            it->second->handle(request, connection);
        }
    } catch (const ExceptionHandler& e) {
        std::cerr << "Error: " << e.what() << " (Code: " << e.getErrorCode() << ")" << std::endl;
        std::string errorMessage = std::to_string(e.getErrorCode()) + " " + e.what() + "\r\n";
        connection.write(errorMessage);
    }
}
