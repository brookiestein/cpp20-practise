#include <iostream>
#include <vector>

#include "box.h"

static void show(const Box& box);

int
main()
{
        std::vector<Box> boxes {
                Box {1.0, 2.0, 3.0}, Box {2.0, 4.0, 7.0},
                Box {5.0, 1.0, 3.0}, Box {1.0, 2.0, 1.0}
        };

        const double minVolume {6.0};
        std::cout << "Boxes that are less than the min volume are:\n";
        for (const auto& box : boxes)
                if (box < minVolume)
                        show(box);

        std::cout << "Boxes that are greater than the min volume:\n";
        for (const auto& box : boxes)
                if (minVolume < box)
                        show(box);
}

static void
show(const Box& box)
{
        std::cout << "Box: " << box.getLength() << 'x'
                << box.getWidth() << 'x'
                << box.getHeight() << std::endl;
}
