#include "too_many_exceptions.h"

TooManyExceptions::TooManyExceptions(const char* message)
        : m_message {message}
{}

const char*
TooManyExceptions::what() const noexcept
{
        return m_message;
}
