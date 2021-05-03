#include <iostream>

#include "circle.h"

int
main()
{
        Circle circle { {0.0, 0.0}, 3.0 };
        /* This won't compile because an abstract class cannot be instantiated.
         * Not only that, but Shape's constructor is protected. */
        /* Shape shape { {0.0, 0.0} }; */

        std::cout << "The circle's area is " << circle.area() << std::endl;
}
