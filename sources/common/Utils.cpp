/*
** ETIB PROJECT, 2025
** myftp
** File description:
** Utils
*/

#include "Utils.hpp"

std::vector<std::string> Utils::splitStringWhitespace(const std::string& str)
{
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end = 0;

    while ((end = str.find_first_of(" \t\n\r", start)) != std::string::npos) {
        if (end != start) {
            result.push_back(str.substr(start, end - start));
        }
        start = end + 1;
    }
    if (start < str.length()) {
        result.push_back(str.substr(start));
    }
    return result;
}
