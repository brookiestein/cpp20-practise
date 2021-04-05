/* Revisit Exercise 6-3, but this time use a smart pointer to store the array,
 * that is, if you haven’t already done so from the start. A good student
 * should’ve known not to use the low-level memory allocation primitives...
 */

#include <iostream>
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

        std::unique_ptr<double[]> numbers { std::make_unique<double[]> (n) };
        double sum {};

        for (unsigned long i {}; i < n; ++i) {
                numbers[i] = 1.0 / ((i + 1) * (i + 1));
                sum += numbers[i];
        }

        std::cout << "The result is " << std::sqrt(6.0 * sum) << std::endl;
}
