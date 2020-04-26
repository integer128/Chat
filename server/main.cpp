#include <iostream>

#include "chatserver.h"

int main()
{
    try
    {
        boost::asio::io_context io_context;
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), std::atoi("1234"));
        ChatServer server_(io_context, endpoint);
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
