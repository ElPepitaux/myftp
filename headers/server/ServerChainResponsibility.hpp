/*
** ETIB PROJECT, 2025
** myftp
** File description:
** ServerChainResponsibility
*/

#pragma once

#include "ChainResponsibility.hpp"
#include "server/Middleware.hpp"
#include "server/commands/UserHandler.hpp"
#include "server/commands/PortHandler.hpp"

class ServerChainResponsibility : public ChainResponsibility {
    public:
        ServerChainResponsibility();
        ~ServerChainResponsibility();

        void setupRoutes() override;

    protected:
    private:
};
