#include "box.h"

Box::Box() = default;
Box::Box(double side)
        : m_length {side}, m_width {side}, m_height {side}
{
}
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

Box::operator double() const
{
        return getVolume();
}

std::ostream&
operator<<(std::ostream& stream, const Box& box)
{
        return (
                stream
                << box.getLength() << 'x'
                << box.getWidth() << 'x'
                << box.getHeight()
        );
}
