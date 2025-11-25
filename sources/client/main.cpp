/*
** ETIB PROJECT, 2025
** myftp
** File description:
** main
*/

#include "client/Client.hpp"

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cerr << "Usage: " << av[0] << " <host> <port>" << std::endl;
        return 1;
    }

    try {
        std::string host = av[1];
        unsigned short port = static_cast<unsigned short>(std::stoi(av[2]));

        Client ftpClient(host, port);
        ftpClient.run();
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
