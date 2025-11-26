/*
** ETIB PROJECT, 2025
** myftp
** File description:
** Middleware
*/

#include "server/Middleware.hpp"

NbrOfArgumentsMiddleware::NbrOfArgumentsMiddleware(int expectedArgs)
    : _expectedArgs(expectedArgs)
{
}

void NbrOfArgumentsMiddleware::handle(const std::vector<std::string>& request, Connection& connection)
{
    size_t argCount = request.size();

    if (argCount != _expectedArgs) {
        throw ExceptionHandler("Incorrect number of arguments.", 501);
    }
    if (_nextHandler) {
        _nextHandler->handle(request, connection);
    }
}
