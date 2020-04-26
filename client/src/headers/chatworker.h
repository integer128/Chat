#pragma once

#include "chatclient.h"

#include <QObject>

class ChatWorker : public QObject
{
    Q_OBJECT
public:
    explicit ChatWorker(QObject *parent = nullptr);

    void startWorker(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoints);
    void stopWorker();
    Q_INVOKABLE void sendToServer(const QString &message);

private:
    ChatClient* m_client;
};
