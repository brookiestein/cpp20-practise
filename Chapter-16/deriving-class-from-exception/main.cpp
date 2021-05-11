#include <iostream>
#include <stdexcept>

#include "box.h"

int
main()
{
        try {
                Box b1 { 1.0, 2.0, 3.0 };
                std::cout << "b1's volume is: " << b1.volume() << std::endl;

                Box b2 { 1.0, -2.0, 3.0 };
                std::cout << "b2's volume is: " << b2.volume() << std::endl;
        } catch (const std::exception& ex) {
                std::cout << "Exception caught in main(): " << ex.what() << std::endl;
        }
}
