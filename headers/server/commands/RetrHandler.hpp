/*
** ETIB PROJECT, 2025
** myftp
** File description:
** RetrHandler
*/

#pragma once

#include "server/ServerChainResponsibility.hpp"
#include "Utils.hpp"

class RetrHandler : public handler {
    public:
        RetrHandler();
        ~RetrHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
        void _handlePassiveMode(Connection& connection, const std::string& filename);
        void _handleActiveMode(Connection& connection, const std::string& filename);
};

