#include "box.h"

Box::Box()
{
        m_length = m_width = m_height = 1.0;
}

Box::Box(double side)
        : Box {side, side, side}
{
}

Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
{
}

Box::Box(const Box& src)
        : m_length {src.m_length}, m_width {src.m_width}, m_height {src.m_height}
{
}

double
Box::volume() const { return m_length * m_width * m_height; }

double
Box::getLength() const { return m_length; }

double
Box::getWidth() const { return m_width; }

double
Box::getHeight() const { return m_height; }

std::ostream&
operator<<(std::ostream& stream, const Box& box)
{
        return (
                stream <<
                box.getLength() << " x " <<
                box.getWidth()  << " x " <<
                box.getHeight()
        );
}
