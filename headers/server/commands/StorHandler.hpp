/*
** ETIB PROJECT, 2025
** myftp
** File description:
** StorHandler
*/

#pragma once

#include "server/ServerChainResponsibility.hpp"

class StorHandler : public handler {
    public:
        StorHandler();
        ~StorHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
        std::string _handlePassiveMode(Connection& connection);
        std::string _handleActiveMode(Connection& connection);
};

