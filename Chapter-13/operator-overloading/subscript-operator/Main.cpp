#include <iostream>
#include <vector>

#include "Truckload.h"
#include "RandomBoxes.h"
#include "SharedBox.h"

int
main()
{
        Truckload load;

        const size_t boxCount {12};
        for (size_t i {}; i < boxCount; ++i)
                load.addBox(randomSharedBox());

        const size_t toPrint {5};
        std::cout << "The whole Truckload is:\n" << load << std::endl;
        std::cout << "\nThe first " << toPrint << " boxes are:\n";
        for (size_t i {}; i < toPrint; ++i) {
                std::cout << '(' << *(load[i]) << ") " << std::endl;
        }
}
