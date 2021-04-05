#include <iostream>
/* #include <array> */

int
main(void)
{
        unsigned int numbers [] {1, 2, 3, 4, 5};

        unsigned int sum {};
        for (size_t i {}; i < std::size(numbers); i++) {
        /* for (size_t i {}; i < sizeof(numbers) / sizeof(numbers[0]); i++) { */
                sum += numbers[i];
        }

        std::cout << "The sum of array's elements is " << sum << std::endl;
}
