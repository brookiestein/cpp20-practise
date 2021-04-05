#include <iostream>
#include <cmath>
// Here, I'm going to use both the isinf() and the isnan() functions defined in std.

int
main()
{
        double n {1.5};
        std::cout << "Is the division of " << n << " / 0 infinity? "
                << (std::isinf(n / 0.0) ? "Yes" : "No") << std::endl;
        std::cout << "Is the division of 0 / 0 an NaN value? "
                << (std::isnan(0.0 / 0.0) ? "Yes" : "No") << std::endl;
        return 0;
}
