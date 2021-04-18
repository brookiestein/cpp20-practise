#ifndef BOX_H
#define BOX_H

#include <ostream>

class Box
{
        public:
                Box();
                Box(double length, double width, double height);

                double getLength() const;
                double getWidth() const;
                double getHeight() const;
                double getVolume() const;

        private:
                double m_length {1.0};
                double m_width  {1.0};
                double m_height {1.0};
};

std::ostream& operator<<(std::ostream& stream, const Box& box);
Box operator+(const Box& box1, const Box& box2);

#endif
