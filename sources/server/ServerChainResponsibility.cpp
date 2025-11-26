/*
** ETIB PROJECT, 2025
** myftp
** File description:
** ServerChainResponsibility
*/

#include "server/ServerChainResponsibility.hpp"

ServerChainResponsibility::ServerChainResponsibility()
{
}

ServerChainResponsibility::~ServerChainResponsibility()
{
}

void ServerChainResponsibility::setupRoutes()
{
    auto nbrOfArgsMiddlewareUser = std::make_shared<NbrOfArgumentsMiddleware>(2);
    auto userHandler = std::make_shared<UserHandler>();
    nbrOfArgsMiddlewareUser->setNext(userHandler);
    _routes["USER"] = nbrOfArgsMiddlewareUser;
}
