/* Overloading functions with reference parameters. */
#include <iostream>

double larger(double a, double b);
const long& larger(const long& a, const long& b);

int
main(void)
{
        double a_double {3.14}, b_double {5.74};
        int a_int {15}, b_int {10};

        std::cout << larger(a_double, b_double) << std::endl;
        std::cout << larger(static_cast<long>(a_int), static_cast<long>(b_int)) << std::endl;
}

double
larger(double a, double b)
{
        std::cout << "double larger() called." << std::endl;
        return a > b ? a : b;
}

const long&
larger(const long& a, const long& b)
{
        std::cout << "long& larger() called." << std::endl;
        return a > b ? a : b;
}
