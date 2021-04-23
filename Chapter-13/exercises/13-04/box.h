#ifndef BOX_H
#define BOX_H

#include <compare>
#include <ostream>
#include <algorithm>

class Box
{
        public:
                Box();
                explicit Box(double side);
                Box(double length, double width, double height);

                double getLength() const;
                double getWidth() const;
                double getHeight() const;
                double getVolume() const;

                /* Methods to add full support for comparison. */
                std::partial_ordering operator<=>(const Box& box) const;
                std::partial_ordering operator<=>(double volume) const;
                bool operator==(const Box& box) const;
                bool operator==(double volume) const; /* This overload will compare with a Box's volume. */

                Box operator+(const Box& box) const; /* For adding two Boxes. */
                Box operator*(double factor) const; /* For post-multiplying by the given value. */
                Box operator/(double divisor) const; /* For dividing by the given value. */

                /* {Add,Multiply,Divide} and assign the current Box with the other. */
                Box& operator+=(const Box& box);
                Box& operator*=(double factor);
                Box& operator/=(double divisor);

        private:
                double m_length {1.0};
                double m_width  {1.0};
                double m_height {1.0};
};

std::ostream& operator<<(std::ostream& stream, const Box& box);
Box operator*(double factor, const Box& box);
/* This function will do the work of {pre,post}-multiplying
* a Box object. */
Box helper(const Box& box, double value);
bool operator!=(double volume, const Box& box);

#endif
