#include "box.h"

Box::Box(double length, double width, double height)
        : m_length {length},
        m_width {width},
        m_height {height}
{}

Box::~Box() = default;

double
Box::volume() const
{
        return m_length * m_width * m_height;
}
