#include "message.h"

Message::Message(const char* text)
        : m_message { new char [std::strlen(text) + 1] }
{
        strncpy(m_message, text, std::strlen(text));;
}

Message::Message(const Message& src)
        : Message {src.m_message}
{
}

Message::~Message()
{
        delete [] m_message;
}

Message&
Message::operator=(const Message& right_op)
{
        if (&right_op == this)
                return *this;

        const size_t length {std::strlen(right_op.m_message)};
        delete [] m_message;
        m_message = new char [length + 1];
        strncpy(m_message, right_op.m_message, length);
        return *this;
}

Message&
Message::operator=(const std::string& src)
{
        delete[] m_message;
        m_message = new char [src.length() + 1];
        strncpy(m_message, src.c_str(), src.length());
        return *this;
}

const char*
Message::getMessage() const
{
        return m_message;
}

std::ostream&
operator<<(std::ostream& stream, const Message& message)
{
        return (stream << message.getMessage());
}
