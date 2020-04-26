#include "chatworker.h"

ChatWorker::ChatWorker(QObject *parent)
    : QObject { parent }
{

}

void ChatWorker::startWorker(boost::asio::io_context &io_context,
                             const tcp::resolver::results_type& endpoints)
{
    m_client = new ChatClient(io_context, endpoints);
}

void ChatWorker::stopWorker()
{
    m_client->close();
}

void ChatWorker::sendToServer(const QString &message)
{
    char line[Packet::BODY_LENGTH + 1];
    strcpy(line, message.toStdString().c_str());

    Packet temp;
    temp.body_length(std::strlen(line));
    std::memcpy(temp.body(), line, temp.body_length());
    temp.encode_header();
    m_client->write(temp);
}
