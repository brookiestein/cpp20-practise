#ifndef BOX_H
#define BOX_H

#include <ostream>
#include <compare>
#include <algorithm> /* This is used in the implementation file! */

class Box
{
        public:
                Box();
                Box(double length, double width, double height);

                double getLength() const;
                double getWidth() const;
                double getHeight() const;
                double getVolume() const;
                std::partial_ordering operator<=>(const Box& box) const;
                std::partial_ordering operator<=>(double volume) const;
                bool operator==(const Box& box) const = default;
                Box& operator+=(const Box& box);
                Box operator+(const Box& box) const;

        private:
                double m_length {1.0};
                double m_width  {1.0};
                double m_height {1.0};
};

std::ostream& operator<<(std::ostream& stream, const Box& box);

#endif
