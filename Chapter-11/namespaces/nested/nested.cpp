/* A nested namespace is that that is inside another one. */
#include <iostream>

namespace math
{
        const double PI { 3.141592653589793 };
        namespace squaring
        {
                double power(double base = PI, double exponent = 1);
                double power(double base, double exponent)
                {
                        double base_cpy { base };
                        for (double i {1}; i < exponent; ++i)
                                base *= base_cpy;
                        return base;
                }
        }
}

int
main(void)
{
        double base {5}, exponent {3};
        double result { math::squaring::power(base, exponent) };
        std::cout << result << std::endl;
        /* Using the default parameters. */
        std::cout << math::squaring::power() << std::endl;
}
