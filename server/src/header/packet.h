#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

class Packet
{
public:
    enum {
        HEADER_LENGTH    = 4,
        BODY_LENGTH      = 512
    };

    Packet()
        : m_body_length { 0 }
    {}

    const char* data() const
    {
        return m_data;
    }

    char* data()
    {
        return m_data;
    }

    unsigned long long length() const
    {
        return HEADER_LENGTH + m_body_length;
    }

    const char* body() const
    {
        return m_data + HEADER_LENGTH;
    }

    char* body()
    {
        return m_data + HEADER_LENGTH;
    }

    unsigned long long body_length() const
    {
        return m_body_length;
    }

    void body_length(std::size_t new_length)
    {
        m_body_length = new_length;
        if (m_body_length > BODY_LENGTH)
            m_body_length = BODY_LENGTH;
    }

    bool decode_header()
    {
        char header[HEADER_LENGTH + 1] = "";
        std::strncat(header, m_data, HEADER_LENGTH);
        m_body_length = std::atoi(header);
        if (m_body_length > BODY_LENGTH)
        {
            m_body_length = 0;
            return false;
        }
        return true;
    }

    void encode_header()
    {
        char header[HEADER_LENGTH + 1] = "";
        std::sprintf(header, "%4d", static_cast<int>(m_body_length));
        std::memcpy(m_data, header, HEADER_LENGTH);
    }

private:
    char m_data[HEADER_LENGTH + BODY_LENGTH];
    unsigned long long m_body_length;
};
