#include <iostream>
#include <random>
#include <functional>
#include <vector>

#include "box.h"
#include "PRNG.h"

int
main()
{
        std::random_device seeder;
        auto random { Random(static_cast<int>(seeder())) };
        const size_t boxesCount {5};
        std::vector<Box> boxes;

        for (size_t i {}; i < boxesCount; ++i)
                boxes.push_back(Box {
                                static_cast<double>(random()),
                                static_cast<double>(random()),
                                static_cast<double>(random())
                        });

        for (const auto& box : boxes)
                std::cout << "Box (" << box << ')' << std::endl;
}
