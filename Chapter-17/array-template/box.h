#ifndef BOX_H
#define BOX_H

class Box
{
public:
        Box(double length = 1.0, double width = 1.0, double height = 1.0);
        virtual ~Box();
        double volume() const;
private:
        double m_length;
        double m_width;
        double m_height;
};

#endif
