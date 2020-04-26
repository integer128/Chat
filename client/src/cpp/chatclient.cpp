#include "chatclient.h"

ChatClient::ChatClient(boost::asio::io_context &io_context, const tcp::resolver::results_type& endpoints)
    : m_ioContext(io_context),
      m_socket(io_context)
{
    doConnect(endpoints);
}

void ChatClient::write(const Packet &msg)
{
    boost::asio::post(
                m_ioContext,
                [this, msg]()
    {
        bool writeInProgress = !m_writeMsgs.empty();
        m_writeMsgs.push_back(msg);
        if (!writeInProgress)
        {
            doWrite();
        }
    });
}

void ChatClient::close()
{
    boost::asio::post(m_ioContext, [this]() { m_socket.close(); });
}

void ChatClient::doConnect(const tcp::resolver::results_type& endpoints)
{
    boost::asio::async_connect(
                m_socket,
                endpoints,
                [this](boost::system::error_code ec, tcp::endpoint)
    {
        if (!ec)
        {
            doReadHeader();
        }
    });
}

void ChatClient::doReadHeader()
{
    boost::asio::async_read(
                m_socket,
                boost::asio::buffer(m_readMsg.data(), Packet::HEADER_LENGTH),
                [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec && m_readMsg.decode_header())
        {
            doReadBody();
        }
        else
        {
            m_socket.close();
        }
    });
}

void ChatClient::doReadBody()
{
    boost::asio::async_read(
                m_socket,
                boost::asio::buffer(m_readMsg.body(), m_readMsg.body_length()),
                [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec)
        {
            QString temp(QString::fromUtf8(m_readMsg.body(), m_readMsg.body_length()));
            //TODO: ADD temp to model
            doReadHeader();
        }
        else
        {
            m_socket.close();
        }
    });
}

void ChatClient::doWrite()
{
    boost::asio::async_write(
                m_socket,
                boost::asio::buffer(m_writeMsgs.front().data(), m_writeMsgs.front().length()),
                [this](boost::system::error_code ec, std::size_t /*length*/)
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
            m_socket.close();
        }
    });
}
