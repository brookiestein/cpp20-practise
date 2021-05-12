/* In this exercise I decided to put the exceptions all together because
 * I'm going to use all of them in this program. I don't think this is
 * a good idea in other contexts, though. */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class NotANumber : public std::domain_error
{
public:
        NotANumber(const std::string& message)
                : std::domain_error(message),
                m_message {message}
        {}
        const char* what() const noexcept override { return m_message.c_str(); }
private:
        std::string m_message;
};

class NegativeNumber : public std::domain_error
{
public:
        NegativeNumber(const std::string& message, int value)
                : std::domain_error(message)
        {
                m_message = message + " Value: " + std::to_string(value);
        }
        const char* what() const noexcept override { return m_message.c_str(); }
private:
        std::string m_message;
};

class OddNumber : public std::domain_error
{
public:
        OddNumber(const std::string& message, int value)
                : std::domain_error(message)
        {
                m_message = message + " Value: " + std::to_string(value);
        }
        const char* what() const noexcept override { return m_message.c_str(); }
private:
        std::string m_message;
};

#endif
