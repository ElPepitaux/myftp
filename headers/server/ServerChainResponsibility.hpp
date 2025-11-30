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
#include "server/commands/PassHandler.hpp"
#include "server/commands/ListHandler.hpp"
#include "server/commands/StorHandler.hpp"
#include "server/commands/PasvHandler.hpp"
#include "server/commands/RetrHandler.hpp"
#include "server/commands/HelpHandler.hpp"
#include "server/commands/QuitHandler.hpp"

class ServerChainResponsibility : public ChainResponsibility {
    public:
        ServerChainResponsibility();
        ~ServerChainResponsibility();

        void setupRoutes() override;

    protected:
    private:
};
