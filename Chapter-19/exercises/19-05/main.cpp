#include <iostream>
#include <memory>
#include <vector>

#include "Box.h"
#include "Truckload.h"
#include "RandomBoxes.h"
#include "DeliveryTruck.hpp"

void showBoxes(const Truckload& truck);

int
main()
{
        Truckload truck;
        const size_t num_of_boxes {5};
        /* Add 5 random boxes to the truckload. */
        for (size_t i {}; i < num_of_boxes; ++i)
                truck.addBox(std::make_shared<Box>(randomBox()));

        std::cout << "All boxes in the truckload:\n";
        showBoxes(truck);

        DeliveredBoxes delivery_boxes;
        DeliveryTruck delivery {
                truck,
                delivery_boxes,
                [] (size_t& count) { ++count; }
        };

        std::cout << std::endl;
        const size_t boxes_to_deliver { 6 };
        for (size_t i {}; i < boxes_to_deliver; ++i)
                delivery.deliverBox();

        std::cout << "\nAfter deliverying " << boxes_to_deliver
                << " these are the remaining boxes:\n";
        showBoxes(truck);
}

void
showBoxes(const Truckload& truck)
{
        auto iter { truck.getIterator() };
        auto box { iter.getFirstBox() };
        while (box) {
                std::cout << *box << std::endl;
                box = iter.getNextBox();
        }
}
