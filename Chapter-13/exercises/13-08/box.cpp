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

auto
Box::operator <=>(const Box& box) const
{
        return getVolume() <=> box.getVolume();
}

auto
Box::operator <=>(double volume) const
{
        return getVolume() <=> volume;
}

bool
Box::operator ==(const Box& box) const
{
        return m_length == box.m_length &&
                m_width == box.m_width &&
                m_height == box.m_height;
}

Box
Box::operator *(double factor) const
{
        return Box {
                m_length * factor,
                m_width  * factor,
                m_height * factor
        };
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
