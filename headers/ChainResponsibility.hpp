/*
** ETIB PROJECT, 2025
** myftp
** File description:
** ChainResponsibility
*/

#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "Connection.hpp"


class handler {
    public:
        virtual ~handler() = default;
        virtual void setNext(handler* nextHandler) = 0;
        virtual handler* getNext() const = 0;
        virtual void handle(const std::string& request, Connection& connection) = 0;
};

class ChainResponsibility {
    public:
        ChainResponsibility();
        ~ChainResponsibility();

        void handleRequest(const std::string& route, const std::string& request, Connection& connection);

    protected:
        std::map<std::string, std::shared_ptr<handler>> _routes;
    private:
};

