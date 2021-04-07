/* Simplified: Classes are user-defined data types. */
#include <iostream>
#include <cstdlib>

#include "Box.h"

void
usage(void)
{
        std::cout << "usage: ./prog <length> <width> <height>" << std::endl;
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
        Box box2 {}; /* A Box using the default values, 1.0. */

        std::cout << "Box's volume is " << box.getVolume() << std::endl;
        std::cout << "Box 2's volume is " << box2.getVolume() << std::endl;
}
