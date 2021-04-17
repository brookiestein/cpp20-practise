#include "Box.h"

Box::Box() = default;

Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
{
}

double
Box::volume() const
{
        return m_length * m_width * m_height;
}

int
Box::compare(const Box& box)
{
        if (volume() < box.volume()) return -1;
        if (volume() == box.volume()) return 0;
        return +1;
}

void
Box::listBox() const
{
        std::cout << "Box(" << m_length << ' '
                << m_width << ' '
                << m_height << ')' << std::endl;
}
