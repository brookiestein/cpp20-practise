#include "box.h"

Box::Box() = default;
Box::Box(double length, double width, double height)
        : m_length {std::max(length, width)},
        m_width {std::min(length, width)},
        m_height {height}
{
}

double
Box::getLength() const { return m_length; }

double
Box::getWidth() const { return m_width; }

double
Box::getHeight() const { return m_height; }

double
Box::getVolume() const
{
        return m_length * m_width * m_height;
}

std::ostream&
operator<<(std::ostream& stream, const Box& box)
{
        stream
                << '('
                << box.getLength() << ' '
                << box.getWidth() << ' '
                << box.getHeight()
                << ')';
        return stream;
}

std::partial_ordering
Box::operator<=>(const Box& box) const
{
        return getVolume() <=> box.getVolume();
}

std::partial_ordering
Box::operator<=>(double volume) const
{
        return getVolume() <=> volume;
}

Box&
Box::operator+=(const Box& box)
{
        m_length += std::max(m_length, box.m_length);
        m_width  += std::max(m_width, box.m_width);
        m_height += box.m_height;
        return *this;
}

Box
Box::operator+(const Box& box) const
{
        Box copy {*this};
        copy += box;
        return copy;
}
