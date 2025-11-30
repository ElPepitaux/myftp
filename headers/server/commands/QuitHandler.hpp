/*
** ETIB PROJECT, 2025
** myftp
** File description:
** QuitHandler
*/

#pragma once

#include "ChainResponsibility.hpp"

class QuitHandler : public handler {
    public:
        QuitHandler();
        ~QuitHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
};


