#include "server/commands/PasvHandler.hpp"
#include <sstream>

PasvHandler::PasvHandler() {
}

PasvHandler::~PasvHandler() {
}

void PasvHandler::handle(const std::vector<std::string>& request, Connection& connection) {
    if (request[0] != "PASV") {
        throw ExceptionHandler("Invalid command for PasvHandler", 500);
    }

    // Create new acceptor on random port
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::tcp::v4(), 0);

    connection.getDataAcceptor().open(ep.protocol());
    connection.getDataAcceptor().set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    connection.getDataAcceptor().bind(ep);
    connection.getDataAcceptor().listen();

    // Get final bound endpoint
    boost::asio::ip::tcp::endpoint dataEndpoint = connection.getDataAcceptor().local_endpoint();

    // Store the endpoint instead of closing previous
    connection.setPasvEndpoint(dataEndpoint);

    // Format PASV response
    boost::asio::ip::address_v4 addr = dataEndpoint.address().to_v4();
    uint16_t port = dataEndpoint.port();

    unsigned char h1 = (addr.to_ulong() >> 24) & 0xFF;
    unsigned char h2 = (addr.to_ulong() >> 16) & 0xFF;
    unsigned char h3 = (addr.to_ulong() >>  8) & 0xFF;
    unsigned char h4 = (addr.to_ulong()      ) & 0xFF;
    unsigned char p1 = (port >> 8) & 0xFF;
    unsigned char p2 = port & 0xFF;

    std::ostringstream oss;
    oss << "227 Entering Passive Mode ("
        << (int)h1 << "," << (int)h2 << "," << (int)h3 << "," << (int)h4 << ","
        << (int)p1 << "," << (int)p2 << ")." << CRLF;

    connection.write(oss.str());

    std::cout << "Passive mode set up on "
              << addr.to_string() << ":" << port << std::endl;  
    // Update connection mode
    connection.setMode(Connection::MODE::PASSIVE);
    connection.setDataAddress(addr.to_string());
    connection.setDataPort(port);
}
