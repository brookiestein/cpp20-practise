#ifndef BOX_H
#define BOX_H

#include <compare>
#include <ostream>

class Box
{
        public:
                Box();
                Box(double side);
                Box(double length, double width, double height);

                double getLength() const;
                double getWidth() const;
                double getHeight() const;
                double getVolume() const;
                std::partial_ordering operator<=>(const Box& box) const;
                std::partial_ordering operator<=>(double volume) const;
                bool operator==(const Box& box) const;
                Box operator*(double factor) const;

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

#endif
