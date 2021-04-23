#include "box.h"

Box::Box() = default;

Box::Box(double side)
        : m_length {side}, m_width {side}, m_height {side}
{}

Box::Box(double length, double width, double height)
        : m_length { std::max(length, width) },
        m_width { std::min(length, width) },
        m_height {height}
{
}

double
Box::getLength() const
{
        return m_length;
}

double
Box::getWidth() const
{
        return m_width;
}

double
Box::getHeight() const
{
        return m_height;
}

double
Box::getVolume() const
{
        return m_length * m_width * m_height;
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

bool
Box::operator==(const Box& box) const
{
        return m_length == box.m_length &&
                m_width == box.m_width &&
                m_height == box.m_height;
}

/* Implementing these functions in terms of their operation/assignment version. */
Box
Box::operator+(const Box& box) const
{
        Box copy {*this};
        copy += box;
        return copy;
}

Box
Box::operator*(double factor) const
{
        Box copy {*this};
        copy *= factor;
        return copy;
}

Box
operator*(double factor, const Box& box)
{
        Box copy {box};
        copy *= factor;
        return copy;
}

Box
Box::operator/(double divisor) const
{
        Box copy {*this};
        copy /= divisor;
        return copy;
}

Box&
Box::operator+=(const Box& box)
{
        m_length = std::max(m_length, box.getLength());
        m_width  = std::max(m_width, box.getWidth());
        m_height += box.getHeight();
        return *this;
}

Box&
Box::operator*=(double factor)
{
        m_length *= factor;
        m_width  *= factor;
        m_height *= factor;
        return *this;
}

Box&
Box::operator/=(double divisor)
{
        m_length /= divisor;
        m_width  /= divisor;
        m_height /= divisor;
        return *this;
}

std::ostream&
operator<<(std::ostream& stream, const Box& box)
{
        return (
                stream
                << box.getLength() << ' '
                << box.getWidth() << ' '
                << box.getHeight()
        );
}
