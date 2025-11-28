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
#include <fstream>
#include <iostream>

class Utils {
    public:
        Utils() = default;
        ~Utils() = default;

        static std::vector<std::string> splitStringWhitespace(const std::string& str);
        static std::vector<std::string> splitString(const std::string& str, char delimiter);

        static std::string getFileContent(const std::string &path);

        static bool writeFileContent(const std::string &path, const std::string &content);

    protected:
    private:
};

