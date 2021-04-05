#include <iostream>
#include <limits>

int
main()
{
        float positive_infinity         = std::numeric_limits<float>::infinity();
        double negative_infinity        = -std::numeric_limits<double>::infinity();
        long double non_a_number        = std::numeric_limits<long double>::quiet_NaN();

        std::cout << "Positive infinity: " << positive_infinity << std::endl;
        std::cout << "Negative infinity: " << negative_infinity << std::endl;
        std::cout << "Non-A-Number: " << non_a_number << std::endl;
        return 0;
}
