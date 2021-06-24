#ifndef BOX_HPP
#define BOX_HPP

#include <ostream>
#include <compare>

class Box
{
public:
        Box(double length, double width, double height);
        std::partial_ordering operator<=>(const Box& b) const;
        std::partial_ordering operator<=>(const double& volume) const;
        double getLength() const noexcept;
        double getWidth() const noexcept;
        double getHeight() const noexcept;
        double volume() const noexcept;
private:
        double m_length;
        double m_width;
        double m_height;
};

std::ostream& operator<<(std::ostream& out, const Box& b);

#endif
