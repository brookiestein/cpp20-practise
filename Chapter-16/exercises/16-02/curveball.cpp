#include "curveball.h"

CurveBall::CurveBall(const char* message)
        : m_message {message}
{}

CurveBall::~CurveBall() = default;

const char*
CurveBall::what() const noexcept
{
        return m_message;
}
