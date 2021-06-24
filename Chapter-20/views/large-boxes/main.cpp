#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "box.hpp"

int
main()
{
        using namespace std::ranges::views;
        std::vector<Box> boxes {
                Box { 7, 8, 9 }, Box { 1, 2, 3 },
                Box { 4, 5, 6 }, Box { 10, 11, 12 }
        };

        const double required_volume { 130 };
        std::vector<Box*> larger_boxes;

        std::ranges::copy(
        boxes | filter([=] (const Box& b) { return b >= required_volume; })
              | transform([] (Box& b) { return &b; }),
        back_inserter(larger_boxes)
        );

        std::cout << "Larger boxes:" << std::endl;
        std::for_each(larger_boxes.begin(), larger_boxes.end(),
                [] (Box*& b) { std::cout << *b << std::endl; }
        );
}
