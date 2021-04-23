/* Exercise 13-4. If we allow my_box <= 6.0 and 6.0 <= my_box , then why not allow */
/* my_box == 6.0 and 6.0 != my_box ? How many operator functions do you need to */
/* accomplish this? Extend the Box class of Ex13_04 and try out your latest operator. */

#include <iostream>
#include <vector>

#include "box.h"

int
main()
{
        const std::vector<Box> boxes {
                Box {2.0, 1.5, 3.0}, Box {1.0, 3.0, 5.0},
                Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 2.0}
        };

        const Box theBox {3.0, 1.0, 4.0};

        for (const auto& box : boxes)
                if (theBox > box)
                        std::cout << "Box: (" << theBox << ") is greater than ("
                                << box << ')' << std::endl;

        std::cout << std::endl;

        for (const auto& box : boxes)
                if (theBox != box)
                        std::cout << "Box: (" << theBox << ") is not equal to ("
                                << box << ')' << std::endl;

        std::cout << std::endl;

        for (const auto& box : boxes)
                if (6.0 != box)
                        std::cout << "6.0 is not the volume of Box ("
                                << box << ')' << std::endl;
}
