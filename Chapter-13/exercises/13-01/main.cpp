/* Exercise 13-1. Define an operator function in the Box class from Ex13_05 that allows */
/* a Box object to be post-multiplied by a numeric value to produce a new object that */
/* has a height that is n times the original object. This should work for both integer and */
/* fractional multiples. Demonstrate that your operator function works as it should. */

#include <iostream>

#include "box.h"

int
main()
{
        Box box0 {2.2, 3.2, 7.2};
        Box box1 {box0 * 5.0};

        std::cout << "Box 0: (" << box0 << ')' << std::endl;
        std::cout << "Box 1: (" << box1 << ')' << std::endl;
}
