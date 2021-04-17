#ifndef RANDOM_BOXES
#define RANDOM_BOXES

#include <memory>
#include <random>
#include <functional>

#include "Box.h"

/* Creates a pseudorandom number generator (PRNG) for random doubles
 * between 0 and max. */
auto createUniformPseudoRandomNumberGenerator(double max);
std::shared_ptr<Box> randomSharedBox();
Box randomBox();

#endif
