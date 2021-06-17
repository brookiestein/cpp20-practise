#ifndef DELIVERY_TRUCK_HPP
#define DELIVERY_TRUCK_HPP

#include <exception>
#include <iostream>
#include <functional>
#include <memory>
#include <vector>

#include "Truckload.h"
#include "Box.h"

void logDelivery(const Box& box);

class DeliveredBoxes
{
public:
        void operator()(Box delivered);
        void get() const noexcept;
private:
        std::vector<Box> boxes;
};

class DeliveryTruck
{
public:
        DeliveryTruck(Truckload& truck, std::function<void(Box)> callback,
                std::function<void(size_t&)> counter);
        void deliverBox();
        void registerOnDelivery(std::function<void(Box)>& callback);
        size_t boxesDelivered() const noexcept;
private:
        Truckload& m_truck;
        std::vector<std::function<void(Box)>> m_delivered;
        std::function<void(size_t&)> m_counter;
        Truckload::Iterator m_iter;
        size_t boxes_delivered;
};

#endif
