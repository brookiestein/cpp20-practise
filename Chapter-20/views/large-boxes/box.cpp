#include "box.hpp"

Box::Box(double length, double width, double height)
        : m_length (length)
        , m_width (width)
        , m_height (height)
{}

std::partial_ordering
Box::operator<=>(const Box& b) const
{
        return volume() <=> b.volume();
}

std::partial_ordering
Box::operator<=>(const double& volume) const
{
        return this->volume() <=> volume;
}

double
Box::getLength() const noexcept
{
        return m_length;
}

double
Box::getWidth() const noexcept
{
        return m_width;
}

double
Box::getHeight() const noexcept
{
        return m_height;
}

double
Box::volume() const noexcept
{
        return getLength() * getWidth() * getHeight();
}

std::ostream&
operator<<(std::ostream& out, const Box& b)
{
        return (
                out << " [*] Box(" << b.getLength() <<  ' '
                << b.getWidth() << ' ' << b.getHeight()
                << ')'
        );
}
