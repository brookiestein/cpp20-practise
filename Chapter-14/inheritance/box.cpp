#include "box.h"

Box::Box()
{
        std::cout << "Box() called." << std::endl;
        m_length = m_width = m_height = 1.0;
}

Box::Box(double side)
        : Box {side, side, side}
{
        std::cout << "Box(double) called." << std::endl;
}

Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
{
        std::cout << "Box(double, double, double) called." << std::endl;
}

double
Box::volume() const { return m_length * m_width * m_height; }

double
Box::getLength() const { return m_length; }

double
Box::getWidth() const { return m_width; }

double
Box::getHeight() const { return m_height; }
