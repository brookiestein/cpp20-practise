/* Making use of implicit conversions from a primitive int
 * to an Integer object. */

#include <iostream>

#include "integer.h"

int
main()
{
        Integer one {1};
        Integer two {2};
        Integer three { one * two / one - one + two }; /* Expects 3. */
        int answer { ((three + two) * (three * two + two) + two).getValue() };

        std::cout << "One's value: " << one << std::endl;
        std::cout << "Two's value: " << two << std::endl;
        std::cout << "Three's value: " << three << std::endl;
        std::cout << "The answer is " << answer << std::endl;
}
