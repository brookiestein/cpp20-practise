#ifndef SHAPE_H
#define SHAPE_H

#include <cmath>

#include "point.h"

class Shape
{
        public:
                Shape(const Point& point)
                        : m_point {point}
                {}
                virtual ~Shape() = default;

                virtual double area() const = 0;
                virtual void scale(double factor) = 0;
                virtual void move(const Point& point) { m_point = point; }
                virtual double perimeter() const = 0;

        private:
                Point m_point;
};

#endif
