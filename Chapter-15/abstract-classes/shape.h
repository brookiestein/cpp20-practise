#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape
{
        protected:
                Shape(const Point& point)
                        : m_point {point}
                {}
                virtual ~Shape() = default;

                virtual double area() const = 0;
                virtual void scale(double factor) = 0;
                virtual void move(const Point& point) { m_point = point; }

        private:
                Point m_point;
};

#endif
