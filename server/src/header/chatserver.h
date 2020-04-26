#pragma once

#include "chatsession.h"

class ChatServer
{
public:
    ChatServer(boost::asio::io_context& io_context, const tcp::endpoint& endpoint);

private:
    void doAccept();
    tcp::acceptor m_acceptor;
    ChatRoom m_room;
};
