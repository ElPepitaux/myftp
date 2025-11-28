/*
** ETIB PROJECT, 2025
** myftp
** File description:
** CwdHandler
*/

#pragma once

#include "ChainResponsibility.hpp"

class CwdHandler : public handler {
    public:
        CwdHandler();
        ~CwdHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
};


