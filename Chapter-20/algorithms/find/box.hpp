#ifndef BOX_HPP
#define BOX_HPP

class Box
{
public:
        Box(double length, double width, double height);
        bool operator==(const Box& other) const noexcept;
        bool operator>(const double& volume) const noexcept;
        double volume() const noexcept;
private:
        double m_length;
        double m_width;
        double m_height;
};

#endif
