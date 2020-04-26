#include "chatmodel.h"

ChatModel::ChatModel(QObject *parent)
    : QAbstractListModel { parent }
{

}

int ChatModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_model.size();
}

QVariant ChatModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    const Node &node = m_model.at(index.row());

    switch (role)
    {
    case Roles::MessageRole:    return node.message;
    default:                    return QVariant {};
    }
}

QHash<int, QByteArray> ChatModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::MessageRole] = "message_";
    return roles;
}

bool ChatModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
    {
        return false;
    }

    switch (role)
    {
    case MessageRole: m_model[index.row()].message = value.toString(); break;
    default: return false;
    }
    emit dataChanged(index, index, QVector<int>() << role);
    return true;
}

Qt::ItemFlags ChatModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

void ChatModel::addMessage(const QString &message_)
{
    emit beginInsertRows(QModelIndex{}, m_model.size(), m_model.size());

    Node new_node;
    new_node.message = message_;
    m_model.push_back(new_node);

    emit endInsertRows();
}
