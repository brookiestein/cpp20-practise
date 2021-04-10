/* Simplified: Classes are user-defined data types. */
/* #include <iostream> */
#include <string>
#include <cstdlib>

#include "Box.h"

static void printVolume(const std::string& message, const Box& box);

void
usage(void)
{
        std::cout
                << "usage: ./prog <length> <width> <height>"
                << std::endl;
}

int
main(int argc, char *argv[])
{
        if (argc < 4) {
                usage();
                return -1;
        }

        unsigned index {1};
        const double length   = std::atof(argv[index++]);
        const double width    = std::atof(argv[index++]);
        const double height   = std::atof(argv[index]);

        Box box {length, width, height};
        Box box2 {}; /* Using the default values, 1.0. */
        Box cube {5.0};
        Box boxes[6] { box, box2, cube, Box {5.0, 6.0, 7.0} };

        for (size_t i {}; i < 6; ++i) {
                std::cout << "Box at " << i << " index's volume is "
                        << boxes[i].getVolume() << std::endl;
        }

        std::cout << '\n' << "Box class's size: " << sizeof(Box) << '\n';
        std::cout << "There are " << box.getObjectCount()
                << " objects." << std::endl;
}

static void
printVolume(const std::string& message, const Box& box)
{
        std::cout << message << box.getVolume() << std::endl;
}
