#include "Box.h"

Box::Box(double length, double width, double height)
{
        m_length = length;
        m_width  = width;
        m_height = height;
}

double Box::getVolume()
{
        return (m_length * m_width * m_height);
}

void Box::setLength(double length)
{
        m_length = length;
}

void Box::setWidth(double width)
{
        m_width = width;
}

void Box::setHeight(double height)
{
        m_height = height;
}
