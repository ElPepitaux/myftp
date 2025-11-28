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

std::vector<std::string> Utils::splitString(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

std::string Utils::getFileContent(const std::string &path)
{
    std::string fileContent = "";
    std::ifstream file(path);

    if (!file.is_open())
        return fileContent;

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    fileContent = buffer.str();
    return fileContent;
}

bool Utils::writeFileContent(const std::string &path, const std::string &content)
{
    std::ofstream file(path);
    if (!file.is_open())
        return false;

    file << content;
    file.close();
    return true;
}
