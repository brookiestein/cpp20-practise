#include <iostream>

#include "truckload.hpp"
#include "random_boxes.hpp"

int
main()
{
        Truckload load;
        const size_t boxCount { 20 }; /* Number of Box object to be created. */

        /* Create boxCount Box objects. */
        for (size_t i {}; i < boxCount; ++i)
                load.addBox(randomBox());

        std::cout << "The boxes in the Truckload are:\n";
        std::cout << load << std::endl;

        Truckload moveConstructedLoad{ std::move(load) };

        std::cout << "The boxes in the move constructed Truckload are:\n";
        std::cout << moveConstructedLoad << std::endl;

        Truckload moveAssignedLoad;
        moveAssignedLoad = std::move(moveConstructedLoad);

        std::cout << "The boxes in the move assigned Truckload are:\n";
        std::cout << moveAssignedLoad << std::endl;
}
