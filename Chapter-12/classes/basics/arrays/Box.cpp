#include "Box.h"

Box::Box()
{
        ++s_object_count;
        std::cout << "Default constructor called.\n";
}

/* Delegating constructor.
 * It's called so because it delegates the construction
 * task to another constructor.
 * Also, it's a short-hand for making a cube. */
Box::Box(double side)
        : Box {side, side, side}
{
        std::cout << "Cube constructor called.\n";
}

/* A copy constructor is that that copies an object
 * of the same class than it belongs to the object
 * which is being created.
 * It also has to receive a reference-to-const class's parameter!
 * Just an example: */
Box::Box(const Box& src)
        : Box {src.m_length, src.m_width, src.m_height}
{
        std::cout << "Copy constructor called.\n";
}

/* Using member initializing list */
Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
{
        ++s_object_count;
        std::cout << "'Normal' constructor called.\n";
        /* m_length = length; */
        /* m_width  = width; */
        /* m_height = height; */
}

double
Box::getVolume() const
{
        return (m_length * m_width * m_height);
}

void
Box::setLength(double length)
{
        if (length > 0)
                m_length = length;
}

void
Box::setWidth(double width)
{
        if (width > 0)
                m_width = width;
}

void
Box::setHeight(double height)
{
        if (height > 0)
                m_height = height;
}
