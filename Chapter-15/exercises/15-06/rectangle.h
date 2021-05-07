#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cmath>

#include "shape.h"

class Rectangle : public Shape
{
        public:
                Rectangle(const Point& point, double width, double height)
                        : Shape {point}, m_width {width}, m_height {height}
                {}

                double getWidth() const { return m_width; };
                double getHeight() const { return m_height; };
                double perimeter() const override { return m_width * m_height * 2.0; }
                void scale(double factor) override { m_width *= factor; m_height *= factor; }
                double area() const override { return m_width * m_height; }

        private:
                double m_width;
                double m_height;
};

#endif
