/* Write a program that reads an array size from the keyboard and dynamically
 * allocates an array of that size to hold floating-point values. Using pointer notation, initialize all
 * the elements of the array so that the value of the element at index position n is 1 / (n + 1) 2 .
 * Calculate the sum of the elements using array notation, multiply the sum by 6, and output the
 * square root of that result.
 */

#include <iostream>
#include <cmath>

int
main(void)
{
        int limit {};

        std::cout << "How large would you like the array to be? ";
        std::cin >> limit;

        if (limit <= 0) {
                std::cout << "Nothing to do." << std::endl;
                return 0;
        }

        auto* numbers { new double[limit] {} };
        double sum {};

        for (int i {}; i < limit; ++i) {
                *(numbers + i) = 1.0 / ((i + 1) * (i + 1));
                sum += *(numbers + i);
        }

        delete[] numbers;
        numbers = nullptr;

        std::cout << "The result is " << std::sqrt(6.0 * sum) << std::endl;
}
