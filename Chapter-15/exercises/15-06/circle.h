#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>

#include "shape.h"

class Circle : public Shape
{
        public:
                Circle(const Point& center, double radius)
                        : Shape {center}, m_radius {radius}
                {}

                double area() const override
                {
                        return m_radius * m_radius * M_PI;
                }

                void scale(double factor) override
                {
                        m_radius *= factor;
                }

                double perimeter() const override
                {
                        return M_PI * m_radius * 2.0;
                }

        private:
                double m_radius;
};

#endif
