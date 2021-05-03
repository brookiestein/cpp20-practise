#include "box.h"

Box::Box()
        : Box {1.0, 1.0, 1.0}
{
        std::cout << "Box() called." << std::endl;
}

Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
{
        std::cout << "Box(double, double, double) called." << std::endl;
}

Box::~Box()
{
        std::cout << "Box destructor called." << std::endl;
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
