/*
** ETIB PROJECT, 2025
** myftp
** File description:
** Utils
*/

#pragma once

#include <string>
#include <vector>
#include <sstream>

class Utils {
    public:
        Utils() = default;
        ~Utils() = default;

        static std::vector<std::string> splitStringWhitespace(const std::string& str);
        static std::vector<std::string> splitString(const std::string& str, char delimiter);

    protected:
    private:
};

