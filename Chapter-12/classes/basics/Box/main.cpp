/* Simplified: Classes are user-defined data types. */
#include <iostream>
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
        Box copy {box}; /* Initializing a box from another. */
        const Box constBox {cube}; /* A const-copy of cube */
        /* This shouldn't compile because the constBox object is constant,
         * and thus its members. */
        printVolume("constBox's volume is ", constBox);
        /* constBox.setWidth(3.14); */

        printVolume("[User defined] box's volume is ", box);
        printVolume("[Programmed] box's volume is ", box2);
        printVolume("Cube's volume is ", cube);
        printVolume("Copied box's volume is ", copy);

        std::cout << "Testing whether modifying a member variable of the "
                << "source object also modifies the one of the copy."
                << std::endl;

        /* Because the setWidth() and setHeight() mutators return a pointer
         * to the same object that is calling them, I can call these methods
         * together, this is, one following the other.
         * Notice how they're called. Using the -> operator, that is because
         * these methods return a POINTER, and you have to dereferenciate it
         * in order to access its member function.
         * It's not the same than box.setWidth(), because box is not a pointer.
         * So I can access its member function without the need of dereferenciate it*/
        /* Now I can use the . operator because these methods return
         * a reference to the object that is calling them. */
        box.setWidth(5.0).setHeight(5.0);

        std::cout << std::boolalpha
                << (box.getVolume() == copy.getVolume())
                << std::endl;
}

static void
printVolume(const std::string& message, const Box& box)
{
        std::cout << message << box.getVolume() << std::endl;
}
