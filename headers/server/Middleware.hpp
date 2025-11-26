/*
** ETIB PROJECT, 2025
** myftp
** File description:
** Middleware
*/

#pragma once

#include "ChainResponsibility.hpp"

class NbrOfArgumentsMiddleware : public handler {
    public:
        NbrOfArgumentsMiddleware(int expectedArgs);
        ~NbrOfArgumentsMiddleware() override = default;

        void handle(const std::vector<std::string>& request, Connection& connection) override;
    private:
        int _expectedArgs;
};
