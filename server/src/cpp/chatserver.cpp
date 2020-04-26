#include "chatserver.h"

ChatServer::ChatServer(boost::asio::io_context &io_context, const tcp::endpoint &endpoint)
    : m_acceptor(io_context, endpoint)
{
    doAccept();
}

void ChatServer::doAccept()
{
    m_acceptor.async_accept(
                [this](boost::system::error_code ec, tcp::socket socket)
    {
        if (!ec)
        {
            std::make_shared<ChatSession>(std::move(socket), m_room)->start();
        }

        doAccept();
    });
}
