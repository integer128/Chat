#pragma once

#include "packet.h"

class ChatParticipant
{
public:
    virtual ~ChatParticipant() {}
    virtual void deliver(const Packet& msg) = 0;
};
