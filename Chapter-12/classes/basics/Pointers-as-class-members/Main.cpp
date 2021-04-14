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

        auto iterator { load1.getIterator() };
        SharedBox largestBox {iterator.getFirstBox()};
        SharedBox nextBox {iterator.getNextBox()};
        while (nextBox) {
                if (nextBox->compare(*largestBox) > 0)
                        largestBox = nextBox;
                nextBox = iterator.getNextBox();
        }

        std::cout << "\nThe largest box in the first list is:\n";
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
        /* Because the load1 object is not longer used, I'll redefine the iterator */
        iterator = load2.getIterator();
        std::cout << "\nThe second list:\n";
        load2.listBoxes();

        auto smallestBox = iterator.getFirstBox();
        for (auto box = iterator.getNextBox(); box; box = iterator.getNextBox())
                if (box->compare(*smallestBox) < 0)
                        smallestBox = box;

        std::cout << "\nThe smallest box in the second list is\n";
        smallestBox->listBox();
        std::cout << std::endl;
}
