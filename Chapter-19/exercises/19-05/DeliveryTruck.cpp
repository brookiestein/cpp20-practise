#include "DeliveryTruck.hpp"

void
logDelivery(const Box& box)
{
        std::cout << "Delivered box: " << box << std::endl;
}

void
DeliveredBoxes::operator()(Box delivered)
{
        boxes.push_back(delivered);
}

void
DeliveredBoxes::get() const noexcept
{
        std::cout << "\nDelivered boxes:\n";
        for (size_t i {}; i < boxes.size(); ++i)
                std::cout << boxes[i] << std::endl;
}

DeliveryTruck::DeliveryTruck(Truckload& truck,
                std::function<void(Box)> callback,
                std::function<void(size_t&)> counter)
                : m_truck {truck}
                , m_counter {counter}
                , m_iter {truck.getIterator()}
                , boxes_delivered {}
{
        m_delivered.push_back(callback);
}

void
DeliveryTruck::deliverBox()
{
        std::shared_ptr<Box> next_box;
        try {
                next_box = m_truck[0];
        } catch (const std::out_of_range& e) {
                std::cerr << "There are no more boxes to deliver." << std::endl;
                throw;
        }

        for (auto& delivered : m_delivered) {
                delivered(*next_box);
                logDelivery(*next_box);
        }

        m_counter(boxes_delivered);
        m_truck.removeBox(next_box);
}

void
DeliveryTruck::registerOnDelivery(std::function<void(Box)>& callback)
{
        m_delivered.push_back(callback);
}

size_t
DeliveryTruck::boxesDelivered() const noexcept
{
        return boxes_delivered;
}
