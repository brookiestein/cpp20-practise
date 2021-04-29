#include "box.h"

Box::Box()
        : Box {1.0, 1.0, 1.0}
{}

Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
{}

double
Box::volume(int i) const
{
        std::cout << "(Box argument = " << i << ") " << std::endl;
        return m_length * m_width * m_height;
}

void
Box::showVolume() const
{
        std::cout << "Box volume is: " << volume() << std::endl;
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
