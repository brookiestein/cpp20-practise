#ifndef BOX_HPP
#define BOX_HPP

#include <ostream>

class Box
{
public:
        Box(double length, double width, double height);
        double volume() const noexcept;
        friend std::ostream& operator<<(std::ostream& out, const Box& box);
private:
        double m_length;
        double m_width;
        double m_height;
};

#endif
