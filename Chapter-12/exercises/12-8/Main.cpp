#include <iostream>
#include <vector>

#include "Truckload.h"
#include "RandomBoxes.h"
#include "SharedBox.h"

int
main()
{
        Truckload myTrack;
        const size_t boxesCount {4};
        for (size_t i {}; i < boxesCount; ++i)
                myTrack.addBox(randomSharedBox());

        std::cout << "These are the boxes (listed in normal order):\n";
        myTrack.listBoxes();

        std::cout << "\nThese are the boxes, now listed in reverse order:\n";
        myTrack.listBoxesReversed();

        auto iterator { myTrack.getIterator() };
        std::cout << "The last box is:\n";

        iterator.getLastBox()->listBox();
        std::cout << "\nThe penultimate box is:\n";
        iterator.getPreviousBox()->listBox();

        std::cout << "\nThe antepenultimate box is\n";
        iterator.getPreviousBox()->listBox();

        auto largest { iterator.findLargestBox() };
        std::cout << "\nLargest box is:\n";
        largest->listBox();

        myTrack.removeLargestBox(iterator);
        std::cout << "\nThese are the boxes (listed in normal order)\n"
                << "After have deleted the largest box:" << std::endl;
        myTrack.listBoxes();
}
