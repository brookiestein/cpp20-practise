#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
        public:
                Box();
                explicit Box(double side);
                Box(double length, double width, double height);

                double volume() const;

                /* Accessors */
                double getLength() const;
                double getWidth() const;
                double getHeight() const;

        private:
                double m_length;
                double m_width;
                double m_height;
};

#endif
