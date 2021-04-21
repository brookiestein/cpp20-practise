/* The explicit keyword makes implicit conversions imposible. */
/* I don't know whether I've understood wrongly, but making the
 * double() type conversion overload explicit still allows
 * statements like this:
 * `double volume {box}`
 */

#ifndef BOX_H
#define BOX_H

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
                explicit operator double() const;

        private:
                double m_length {1.0};
                double m_width  {1.0};
                double m_height {1.0};
};

std::ostream& operator<<(std::ostream& stream, const Box& box);

#endif
