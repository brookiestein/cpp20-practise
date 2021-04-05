/* Revisit Exercise 6-4 and replace any raw pointers
 * with smart pointers there as well.
 */

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

int
main(void)
{
        unsigned long n {};
        std::cout << "How large would you like the array to be? ";
        std::cin >> n;

        if (n <= 0) {
                std::cout << "Nothing to do." << std::endl;
                return 0;
        }

        auto numbers { std::make_unique<std::vector<double>>(n) };
        double sum {};

        for (unsigned long i {}; i < n; ++i) {
                /* Accessing to the vector inside numbers, so access to the
                 * element in the i index of the vector. */
                (*numbers)[i] = 1.0 / ((i + 1) * (i + 1));
                sum += (*numbers)[i];
        }

        std::cout << "The result is " << std::sqrt(6.0 * sum) << std::endl;
}
