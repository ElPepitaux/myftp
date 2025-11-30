/*
** ETIB PROJECT, 2025
** myftp
** File description:
** DeleHandler
*/

#pragma once

#include "ChainResponsibility.hpp"

class DeleHandler : public handler {
    public:
        DeleHandler();
        ~DeleHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
};


