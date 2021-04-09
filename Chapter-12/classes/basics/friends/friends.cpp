/* A friend function is that that is not part of the class, but
 * can access its members, even its private ones. */

#include <iostream>
#include <memory>

class Box
{
        public:
                Box() : Box {1.0, 1.0, 1.0}
                {
                }

                Box(double length, double width, double height)
                        : m_length {length}, m_width {width}, m_height {height}
                {
                }

                friend double surfaceArea(const Box& box);

        private:
                double m_length {};
                double m_width {};
                double m_height {};
};

double
surfaceArea(const Box& box)
{
        return 2.0 * (box.m_length * box.m_width + box.m_length
                * box.m_height + box.m_height * box.m_width);
}

int
main(void)
{
        Box box1 {2.2, 1.1, 0.5};
        Box box2 {};
        auto box3 { std::make_unique<Box>(15.0, 20.0, 8.0) };

        std::cout << "Box 1's surface area is: " << surfaceArea(box1) << std::endl;
        std::cout << "Box 2's surface area is: " << surfaceArea(box2) << std::endl;
        std::cout << "Box 3's surface area is: " << surfaceArea(*box3) << std::endl;
}
