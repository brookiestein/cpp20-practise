#include <iostream>

#include "box.h"

int
main()
{
        Box box {1.0, 2.0, 3.0};
        Box cube {2.0, 2.0, 2.0};
        Box bigBox {box + cube};

        std::cout << box << std::endl;
        std::cout << cube << std::endl;
        std::cout << bigBox << std::endl; 
}
