/* Simplified: Classes are user-defined data types. */
#include <iostream>

class Box
{
        public:
                /* The default constructor here stands for whether I, or another programmmer
                 * wants to make a Box object without specifying its properties at the moment
                 * of instanciating it, but later. They can just instanciate it with the default
                 * values. i.e. 1.0 */
                Box() {} /* Default constructor. */
                Box(double length, double width, double height)
                {
                        setLength(length);
                        setWidth(width);
                        setHeight(height);
                }

                double getVolume()
                {
                        return (m_length * m_width * m_height);
                }

                /* When I wrote these setter functions I didn't know
                 * how to make a constructor in C++. However, when
                 * I learn that, I'll make a constructor that
                 * receives these three values and just call them.
                 * They're public, though.
                 * Btw, the this keyword, in this case, is not
                 * necessary because we could just use the member
                 * names without any collision with the parameter name
                 * However, I've used it for practising objectives. */
                void setLength(double length)
                {
                        this->m_length = length;
                }

                void setWidth(double width)
                {
                        this->m_width = width;
                }

                void setHeight(double height)
                {
                        this->m_height = height;
                }

        private:
                double m_length {1.0};
                double m_width {1.0};
                double m_height {1.0};
};

int
main(void)
{
        /* Here are two Boxes. One using the default
         * constructor, and the other one using another constructor. */
        Box box1 {};
        Box box2 {2.0, 3.0, 4.0};

        std::cout << "Box 1's volume is " << box1.getVolume() << std::endl; /* 1.0 */
        std::cout << "Box 2's volume is " << box2.getVolume() << std::endl; /* 24.0 */
}
