#ifndef BOX_HPP
#define BOX_HPP

#include <ostream>

class Box
{
public:
        Box(double length, double width, double height)
                : m_length {length}, m_width {width}, m_height {height}
        {}
        double volume() const noexcept { return m_length * m_width * m_height; }
        double getLength() const noexcept { return m_length; }
        double getWidth() const noexcept { return m_width; }
        double getHeight() const noexcept { return m_height; }
        void setLength(double length) { m_length = length; }
        void setWidth(double width) { m_width = width; }
        void setHeight(double height) { m_height = height; }
private:
        double m_length;
        double m_width;
        double m_height;
};


/* I know this is not a good practice, but let's allow this in this
 * case, just because this example is for practicing another thing. */
std::ostream&
operator<<(std::ostream& out, const Box& box)
{
        return out << "Box(" << box.getLength() << ' '
                << box.getWidth() << ' ' << box.getHeight() << ')';
}

#endif
