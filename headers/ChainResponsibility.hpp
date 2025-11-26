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
#include <exception>

class ExceptionHandler : public std::exception {
    public:
        ExceptionHandler(const std::string& message, int errorCode) : _message(message), _errorCode(errorCode) {}
        const char* what() const noexcept override {
            return _message.c_str();
        }
        int getErrorCode() const noexcept {
            return _errorCode;
        }
    private:
        std::string _message;
        int _errorCode;
};

class handler {
    public:
        virtual ~handler() = default;
        void setNext(const std::shared_ptr<handler> &nextHandler);
        std::shared_ptr<handler> getNext();

        virtual void handle(const std::vector<std::string>& request, Connection& connection) = 0;
    protected:
        std::shared_ptr<handler> _nextHandler;
    private:
};

class ChainResponsibility {
    public:
        virtual ~ChainResponsibility() = default;

        virtual void setupRoutes() = 0;

        void handleRequest(const std::string& route, const std::vector<std::string>& request, Connection& connection);

    protected:
        std::map<std::string, std::shared_ptr<handler>> _routes;
    private:
};

