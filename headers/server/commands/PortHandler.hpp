/*
** ETIB PROJECT, 2025
** myftp
** File description:
** PortHandler
*/

#pragma once

#include "server/ServerChainResponsibility.hpp"
#include "Utils.hpp"

class PortHandler : public handler {
    public:
        PortHandler();
        ~PortHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
};
