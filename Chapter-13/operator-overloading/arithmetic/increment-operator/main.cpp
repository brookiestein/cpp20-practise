/* Implementing the prefix and postfix increment operator
 * to our Box class. */

#include <iostream>

#include "box.h"

int
main()
{
        Box box {1.0, 1.0, 1.0};

        std::cout << "Original Box: " << box << std::endl;
        std::cout << "Using postfix operator: " << box++ << std::endl;
        std::cout << "After incrementing with the postfix operator: " << box << std::endl;
        std::cout << "Using prefix operator: " << ++box << std::endl;
        std::cout << "After incrementing with the prefix operator: " << box << std::endl;

        /* This would compile if and only if the returned value of operator++(int)
         * member function of the Box class were non-const.
         * That's the reason why it's recommendable making the returned value of the
         * postfix operator overload const.
         * My tests proved that this doesn't change anything. In other words:
         * One could think that making it would increment box twice, but it doesn't. */

        /* std::cout << '\n' << "Testing whether using ++++ works...\n" << std::endl; */
        /* box++++; */
        /* std::cout << "Box after using ++++: " << box << std::endl; */
}
