/* Comparing non-a-number values */

#include <iostream>
#include <limits>

int
main(void)
{
        const double nan {std::numeric_limits<double>::quiet_NaN()};
        std::cout << std::boolalpha;
        std::cout << "NaN < 1: " << (nan < 1) << std::endl;
        std::cout << "NaN > 1: " << (nan > 1) << std::endl;
        std::cout << "NaN == NaN: " << (nan == nan) << std::endl;
}
