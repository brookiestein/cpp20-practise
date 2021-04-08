/* Simplified: Classes are user-defined data types. */
#include <iostream>
#include <string>
#include <cstdlib>

#include "Box.h"

static void printVolume(const std::string& message, Box& box);

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
        Box copy {box}; /* Initializing a box from another. */

        printVolume("[User defined] box's volume is ", box);
        printVolume("[Programmed] box's volume is ", box2);
        printVolume("Cube's volume is ", cube);
        printVolume("Copied box's volume is ", copy);

        std::cout << "Testing whether modifying a member variable of the "
                << "source object also modifies the one of the copy."
                << std::endl;

        box.setWidth(5.0);
        box.setHeight(5.0);

        std::cout << std::boolalpha
                << (box.getVolume() == copy.getVolume() ? true : false)
                << std::endl;
}

static void
printVolume(const std::string& message, Box& box)
{
        std::cout << message << box.getVolume() << std::endl;
}
