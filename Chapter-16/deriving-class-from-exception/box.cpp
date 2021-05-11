#include "box.h"

Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
{
        if (length <= 0.0 || width <= 0.0 || height <= 0.0)
                throw DimensionException { std::min({length, width, height}) };
}

Box::~Box() = default;

double
Box::volume() const noexcept
{
        return m_length * m_width * m_height;
}
