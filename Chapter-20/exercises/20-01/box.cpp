#include "box.hpp"

Box::Box(double length, double width, double height)
        : m_length (length), m_width (width), m_height (height)
{}

double
Box::volume() const noexcept
{
        return m_length * m_width * m_height;
}

std::ostream&
operator<<(std::ostream& out, const Box& box)
{
        return (
                out << " [*] Box(" << box.m_length << ' '
                << box.m_width << ' ' << box.m_height << ')'
        );
}
