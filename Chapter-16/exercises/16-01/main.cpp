/* Exercise 16-1. Derive your own exception class called CurveBall from the std::exception */
/* class to represent an arbitrary error and write a function that throws this exception */
/* approximately 25% of the time. One way to do this is to generate a random integer between 0 */
/* (inclusive) and 100 (exclusive) and, if the number is less than 25, throw the exception. Define */
/* a main() function to call this function 1,000 times, while recording the number of times an */
/* exception was thrown. At the end, print out the final count. Of course, if all went well, this */
/* number should fluctuate somewhere around 250. */

#include <iostream>
#include <random>
#include <functional>

#include "curveball.h"

static auto
createUniformPseudoRandomNumberGenerator(unsigned min, unsigned max)
{
        std::random_device seeder;
        std::default_random_engine generator { seeder() };
        std::uniform_int_distribution distribution { min, max };
        return std::bind(distribution, generator);
}

static void
generateNumber(size_t& count)
{
        auto random { createUniformPseudoRandomNumberGenerator(0, 100) };
        const size_t howMany {1'000};
        for (size_t i {}; i < howMany; ++i) {
                try {
                        auto number { random() };
                        if (number < 25) {
                                throw CurveBall { "Number is less than 25. Not valid." };
                        }
                } catch (const CurveBall& ex) {
                        std::cout << "Exception caught: " << ex.what() << std::endl;
                        ++count;
                }
        }
}

int
main()
{
        size_t count {};
        generateNumber(count);
        std::cout << "\nNumber of exceptions thrown: " << count << std::endl;
}
