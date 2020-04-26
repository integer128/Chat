#pragma once

#include <QAbstractListModel>
#include <QString>

#include <vector>

class ChatModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ChatModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void addMessage(const QString& message_);

private:

    enum Roles {
        MessageRole = Qt::UserRole + 1
    };

    struct Node {
        QString message;
    };

    std::vector<Node> m_model;
};
