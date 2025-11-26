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
    auto it = _routes.find(route);
    if (it != _routes.end()) {
        it->second->handle(request, connection);
    }
}
