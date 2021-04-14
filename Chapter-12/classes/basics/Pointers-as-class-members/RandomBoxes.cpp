#include "RandomBoxes.h"

auto
createUniformPseudoRandomNumberGenerator(double max)
{
        std::random_device seeder;
        std::default_random_engine generator {seeder()};
        std::uniform_real_distribution distribution {0.0, max};
        return std::bind(distribution, generator);
}

std::shared_ptr<Box>
randomSharedBox()
{
        return std::make_shared<Box>(randomBox());
}

Box
randomBox()
{
        const int dimLimit {100};
        static auto random {createUniformPseudoRandomNumberGenerator(dimLimit)};
        return Box {random(), random(), random()};
}
