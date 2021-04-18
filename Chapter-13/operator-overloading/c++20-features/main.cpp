/* In C++ 20 overloading <=>, and == operators gives us
 * full support for all comparison operators, they are:
 * <, >, <=, >=, ==, !=
 */

#include <iostream>
#include <vector>
#include <string_view>

#include "box.h"

static void show(const Box& box);
static void show(const Box& box1, std::string_view relationship, const Box& box2);

int
main()
{
        const std::vector<Box> boxes {
                Box {1.0, 2.0, 3.0}, Box {1.0, 1.0, 6.0},
                Box {1.0, 2.0, 3.0}, Box {2.0, 3.0, 2.0},
                Box {1.0, 3.0, 4.0}
        };

        const Box theBox {1.0, 3.0, 4.0};

        for (const auto& box : boxes) {
                if (theBox == box) show(theBox, " is equal to ", box);
                else show(theBox, " is not equal to ", box);

                if (theBox < box) show(theBox, " is less than ", box);
                else if (theBox > box) show(theBox, " is greater than ", box);
                /* This is because both Boxes have the same volume but their
                 * dimensions differ. */
                else show(theBox, " is equivalent to ", box);
                std::cout << std::endl;
        }
}

static void
show(const Box& box)
{
        std::cout << "Box: "
                << box.getLength() << 'x'
                << box.getWidth() << 'x'
                << box.getHeight();
}

static void
show(const Box& box1, std::string_view relationship, const Box& box2)
{
        show(box1);
        std::cout << relationship;
        show(box2);
        std::cout << std::endl;
}
