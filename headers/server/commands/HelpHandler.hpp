/*
** ETIB PROJECT, 2025
** myftp
** File description:
** HelpHandler
*/

#pragma once

#include "ChainResponsibility.hpp"

class HelpHandler : public handler {
    public:
        HelpHandler();
        ~HelpHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
};


