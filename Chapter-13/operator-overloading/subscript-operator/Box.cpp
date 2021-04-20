#include "Box.h"

Box::Box() = default;

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

int
Box::compare(const Box& box)
{
        if (getVolume() < box.getVolume()) return -1;
        if (getVolume() == box.getVolume()) return 0;
        return +1;
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
