#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
        public:
                Box();
                Box(double length, double width, double height);

                double volume() const;
                int compare(const Box& box);
                void listBox() const;

        private:
                double m_length {1.0};
                double m_width  {1.0};
                double m_height {1.0};
};

#endif
