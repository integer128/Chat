#pragma once

#include "chatparticipant.h"

#include <memory>
#include <deque>
#include <set>

using ChatParticipantPtr    = std::shared_ptr<ChatParticipant>;
using ChatMessageQueue      = std::deque<Packet>;

class ChatRoom
{
public:
    void join(ChatParticipantPtr participant);
    void leave(ChatParticipantPtr participant);
    void deliver(const Packet &msg);

private:
    std::set<ChatParticipantPtr> participants_;
    enum { MAX_STORAGE_MESSAGES = 100 };
    ChatMessageQueue m_recentMsgs;
};
