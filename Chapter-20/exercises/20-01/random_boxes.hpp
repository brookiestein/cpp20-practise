#ifndef RANDOM_BOXES_HPP
#define RANDOM_BOXES_HPP

#include <functional>
#include <random>

#include "box.hpp"

inline auto
createUniformPseudoRandomNumberGenerator(double max)
{
        std::random_device seeder; /* True random number generator to obtain a seed. (slow) */
        std::default_random_engine generator { seeder() }; /* Efficient pseudo-random generator. */
        std::uniform_real_distribution distribution { 0.0, max };
        return std::bind(distribution, generator); /* ...And in the dark bind them! */
}

inline Box
randomBox()
{
        const int dimLimit { 100 }; /* Upper limit on Box dimensions. */
        static auto random { createUniformPseudoRandomNumberGenerator(dimLimit) };
        return Box { random(), random(), random() };
}

#endif
