#ifndef BOX_H
#define BOX_H

#include <algorithm>

#include "dimension_exception.h"

class Box
{
public:
        Box(double length, double width, double height);
        virtual ~Box();

        double volume() const noexcept;

private:
        double m_length;
        double m_width;
        double m_height;
};

#endif
