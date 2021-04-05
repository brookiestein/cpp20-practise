#include <iostream>
#include <iomanip> // For setprecision() function.
#include <cmath> // For the M_PI constant.

int
main()
{
        std::cout << "The value of the PI constant is " << M_PI << std::endl;
        std::cout << "The value of the PI constant is " << std::setprecision(3) << M_PI << std::endl;
        return 0;
}
