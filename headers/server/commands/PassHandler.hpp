/*
** ETIB PROJECT, 2025
** myftp
** File description:
** PassHandler
*/

#pragma once

#include "ChainResponsibility.hpp"

class PassHandler : public handler {
    public:
        PassHandler();
        ~PassHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
};


