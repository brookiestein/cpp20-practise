#include <iostream>

double
power(double x, int n)
{
        double result {1};
        n = (n >= 0) ? n : -n;
        for (int i {1}; i <= n; ++i)
                result = (n >= 0) ? result * x : result / x;
        return result;
}

int
main(void)
{
        double base {};
        int exponent {};

        std::cout << "Enter the base: ";
        std::cin >> base;
        std::cout << "Enter the exponent: ";
        std::cin >> exponent;

        std::cout << base << " to the " << exponent
                << " is " << power(base, exponent) << std::endl;
}
