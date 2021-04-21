#include <iostream>

#include "box.h"

int
main()
{
        Box box {3.0}; /* A Cube Box. */
        double volume {box}; /* Implicit conversion from a Box object to a primitive double. */

        std::cout << "The Box: (" << box << ')' << std::endl;
        std::cout << "Its volume: " << volume << std::endl;
}
