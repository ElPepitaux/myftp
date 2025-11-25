/*
** ETIB PROJECT, 2025
** myftp
** File description:
** main
*/

#include "server/Server.hpp"

int main()
{
    Server ftp(6000);
    ftp.run();
}
