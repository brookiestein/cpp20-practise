#include <box.hpp>

Box::Box(double length, double width, double height)
        : m_length {length}
        , m_width {width}
        , m_height {height}
{}

bool
Box::operator==(const Box& other) const noexcept
{
        return (
                m_length == other.m_length
                && m_width == other.m_width
                && m_height == other.m_height
        );
}

bool
Box::operator>(const double& volume) const noexcept
{
        return this->volume() > volume;
}

double
Box::volume() const noexcept
{
        return m_length * m_width * m_height;
}
