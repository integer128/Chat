#pragma once

#include "chatroom.h"

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

class ChatSession : public ChatParticipant,
                    public std::enable_shared_from_this<ChatSession>
{
public:
    ChatSession(tcp::socket socket, ChatRoom &room);

    void start();
    void deliver(const Packet &msg);

private:
    void doReadHeader();
    void doReadBody();
    void doWrite();

    tcp::socket m_socket;
    ChatRoom &m_room;
    Packet m_readMsg;
    ChatMessageQueue m_writeMsgs;
};
