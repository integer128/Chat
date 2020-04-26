#pragma once

#include "packet.h"

#include <QString>

#include <boost/asio.hpp>

#include <deque>

using boost::asio::ip::tcp;
using chatMessageQueue = std::deque<Packet>;

class ChatClient
{
public:
    ChatClient(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoints);

    void write(const Packet& msg);
    void close();

private:
    void doConnect(const tcp::resolver::results_type& endpoints);
    void doReadHeader();
    void doReadBody();
    void doWrite();

private:
    boost::asio::io_context& m_ioContext;
    tcp::socket m_socket;
    Packet m_readMsg;
    chatMessageQueue m_writeMsgs;
};
