#pragma once

#include "ChainResponsibility.hpp"
#include "Connection.hpp"

class PasvHandler : public handler {
    public:
        PasvHandler();
        ~PasvHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
};
