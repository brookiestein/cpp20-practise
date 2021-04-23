#include "box.h"

Box::Box() = default;

Box::Box(double side)
        : m_length {side}, m_width {side}, m_height {side}
{}

Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
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

Box
helper(const Box& box, double factor)
{
        return Box {
                box.getLength() * factor,
                box.getWidth()  * factor,
                box.getHeight() * factor
        };
}

Box
Box::operator*(double factor) const
{
        return helper(*this, factor);
}

Box
operator*(double factor, const Box& box)
{
        return helper(box, factor);
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
