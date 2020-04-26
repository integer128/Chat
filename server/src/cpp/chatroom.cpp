#include "chatroom.h"

void ChatRoom::join(ChatParticipantPtr participant)
{
    participants_.insert(participant);
    for (auto msg: m_recentMsgs)
    {
        participant->deliver(msg);
    }
}

void ChatRoom::leave(ChatParticipantPtr participant)
{
    participants_.erase(participant);
}

void ChatRoom::deliver(const Packet &msg)
{
    m_recentMsgs.push_back(msg);
    while (m_recentMsgs.size() > MAX_STORAGE_MESSAGES)
    {
        m_recentMsgs.pop_front();
    }

    for (auto participant: participants_)
    {
        participant->deliver(msg);
    }
}
