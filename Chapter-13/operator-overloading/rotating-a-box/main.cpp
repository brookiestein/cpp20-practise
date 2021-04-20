/* In this simple exercise I'm going to overload the ~ operator
 * to rotate a Box, in the sense of swapping its length with its width. */

#include <iostream>

#include "box.h"

int
main()
{
        Box box {1.0, 2.0, 3.0}; /* A simple Box. */
        Box rotated { ~box };

        std::cout << "Original box (" << box << ')' << std::endl;
        std::cout << "Rotated box (" << rotated << ')' << std::endl;
}
