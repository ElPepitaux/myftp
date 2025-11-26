/*
** ETIB PROJECT, 2025
** myftp
** File description:
** UserHandler
*/

#pragma once

#include "ChainResponsibility.hpp"

class UserHandler : public handler {
    public:
        UserHandler();
        ~UserHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
};


