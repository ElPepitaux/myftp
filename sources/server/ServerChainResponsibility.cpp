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

    _routes["PASS"] = std::make_shared<PassHandler>();

    auto authMiddlewareUser = std::make_shared<AuthenticationMiddleware>();
    auto nbrOfArgsMiddlewarePort = std::make_shared<NbrOfArgumentsMiddleware>(2);
    auto portHandler = std::make_shared<PortHandler>();
    authMiddlewareUser->setNext(nbrOfArgsMiddlewarePort);
    nbrOfArgsMiddlewarePort->setNext(portHandler);
    _routes["PORT"] = authMiddlewareUser;

    auto authMiddlewareList = std::make_shared<AuthenticationMiddleware>();
    auto chooseModeMiddleware = std::make_shared<ChooseModeMiddleware>();
    auto listHandler = std::make_shared<ListHandler>();
    authMiddlewareList->setNext(chooseModeMiddleware);
    chooseModeMiddleware->setNext(listHandler);
    _routes["LIST"] = authMiddlewareList;
}
