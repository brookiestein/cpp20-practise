#include <iostream>
#include <vector>

#include "Truckload.h"
#include "RandomBoxes.h"
#include "SharedBox.h"

int
main()
{
        Truckload load1;

        const size_t boxCount {12};
        for (size_t i {}; i < boxCount; ++i)
                load1.addBox(randomSharedBox());

        std::cout << "The first list:\n";
        load1.listBoxes();

        Truckload copy {load1};
        std::cout << "The copied Truckload:\n";
        copy.listBoxes();

        SharedBox largestBox {load1.getFirstBox()};
        SharedBox nextBox {load1.getNextBox()};
        while (nextBox) {
                if (nextBox->compare(*largestBox) > 0)
                        largestBox = nextBox;
                nextBox = load1.getNextBox();
        }

        std::cout << "\nThe largest box in the first list is ";
        largestBox->listBox();
        std::cout << std::endl;
        load1.removeBox(largestBox);
        std::cout << "\nAfter deleting the largest box, the list contains:\n";
        load1.listBoxes();

        const size_t nBoxes {20};
        std::vector<SharedBox> boxes;
        for (size_t i {}; i < nBoxes; ++i)
                boxes.push_back(randomSharedBox());

        Truckload load2 {boxes};
        std::cout << "\nThe second list:\n";
        load2.listBoxes();

        auto smallestBox = load2.getFirstBox();
        for (auto box = load2.getNextBox(); box; box = load2.getNextBox())
                if (box->compare(*smallestBox) < 0)
                        smallestBox = box;

        std::cout << "\nThe smallest box in the second list is ";
        smallestBox->listBox();
        std::cout << std::endl;
}
