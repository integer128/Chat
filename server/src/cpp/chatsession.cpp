#include "chatsession.h"

ChatSession::ChatSession(tcp::socket socket, ChatRoom &room)
    : m_socket(std::move(socket)),
      m_room(room)
{

}

void ChatSession::start()
{
    m_room.join(shared_from_this());
    doReadHeader();
}

void ChatSession::deliver(const Packet &msg)
{
    bool writeInProgress = !m_writeMsgs.empty();
    m_writeMsgs.push_back(msg);
    if (!writeInProgress)
    {
        doWrite();
    }
}

void ChatSession::doReadHeader()
{
    auto self(shared_from_this());
    boost::asio::async_read(
                m_socket,
                boost::asio::buffer(m_readMsg.data(), Packet::HEADER_LENGTH),
                [this, self](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec && m_readMsg.decode_header())
        {
            doReadBody();
        }
        else
        {
            m_room.leave(shared_from_this());
        }
    });
}

void ChatSession::doReadBody()
{
    auto self(shared_from_this());
    boost::asio::async_read(
                m_socket,
                boost::asio::buffer(m_readMsg.body(), m_readMsg.body_length()),
                [this, self](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec)
        {
            m_room.deliver(m_readMsg);
            doReadHeader();
        }
        else
        {
            m_room.leave(shared_from_this());
        }
    });
}

void ChatSession::doWrite()
{
    auto self(shared_from_this());
    boost::asio::async_write(
                m_socket,
                boost::asio::buffer(m_writeMsgs.front().data(), m_writeMsgs.front().length()),
                [this, self](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec)
        {
            m_writeMsgs.pop_front();
            if (!m_writeMsgs.empty())
            {
                doWrite();
            }
        }
        else
        {
            m_room.leave(shared_from_this());
        }
    });
}
