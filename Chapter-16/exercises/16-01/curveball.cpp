#include "curveball.h"

CurveBall::CurveBall(std::string_view message)
        : m_message {message}
{}

CurveBall::~CurveBall() = default;

const char*
CurveBall::what() const noexcept
{
        return m_message.c_str();
}
