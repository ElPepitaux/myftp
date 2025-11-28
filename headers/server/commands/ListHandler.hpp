/*
** ETIB PROJECT, 2025
** myftp
** File description:
** ListHandler
*/

#pragma once

#include <filesystem>
#include <iostream>
#include <string>

#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "ChainResponsibility.hpp"

class ListHandler : public handler {
    public:
        ListHandler();
        ~ListHandler();

        void handle(const std::vector<std::string>& request, Connection& connection) override;

    protected:
    private:
        std::string _listDirectoryContent(const std::string& path = ".");
};


