#include <iostream>
#include <vector>
#include <random>
#include <functional>

#include "box.h"

static auto
createUniformPseudoRandomNumberGenerator(double max)
{
        std::random_device seeder; /* True random number generator to obtain a seed (slow) */
        std::default_random_engine generator {seeder()}; /* Efficient pseudo-random generator. */
        std::uniform_real_distribution distribution {1.0, max}; /* Generate in [1, max] interval. */
        return std::bind(distribution, generator); /* ... And in the darkness bind them! */
}

int
main()
{
        const double limit {99.0}; /* Upper limit on Box dimensions. */
        auto random { createUniformPseudoRandomNumberGenerator(limit) };

        const size_t boxCount {20};
        std::vector<Box> boxes;
        for (size_t i {}; i < boxCount; ++i)
                boxes.push_back(Box { random(), random(), random() });

        size_t first {};
        size_t second {1};
        double minVolume { (boxes[first] + boxes[second]).getVolume() };

        for (size_t i {}; i < boxCount - 1; ++i) {
                for (size_t j {i + 1}; j < boxCount; ++j) {
                        if (boxes[i] + boxes[j] < minVolume) {
                                first  = i;
                                second = j;
                                minVolume = (boxes[first] + boxes[second])
                                        .getVolume();
                        }
                }
        }

        std::cout << "The two boxes that sum to the smallest volume are\n"
                << boxes[first] << " and " << boxes[second] << '\n';

        std::cout << "The volume of the first box is: "
                << boxes[first].getVolume() << '\n';

        std::cout << "The volume of the second box is: "
                << boxes[second].getVolume() << '\n';

        std::cout << "The sum of these boxes is: "
                << (boxes[first] + boxes[second]) << '\n';

        std::cout << "The volume of the sum is: "
                << minVolume << '\n';

        Box sum {0.0, 0.0, 0.0}; /* We start with an empty Box. */
        for (const auto& box : boxes)
                sum += box;

        std::cout << "The sum of the " << boxCount
                << " boxes is: " << sum << std::endl;
}
