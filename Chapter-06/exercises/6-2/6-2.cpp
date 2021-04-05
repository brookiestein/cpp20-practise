/* Revisit the previous exercise, but instead of accessing the array values using
 * the loop counter, this time you should employ pointer increments (using the ++ operator) to
 * traverse the array when outputting it for the first time. After that, use pointer decrements
 * (using -- ) to traverse the array again in the reverse direction.
 */

#include <iostream>

int
main(void)
{
        const size_t size {50};
        unsigned int odds[size] {};

        for (size_t i {}; i < size; ++i) {
                odds[i] = i * 2 + 1;
        }

        unsigned int *podds {odds};
        const unsigned int perline {10};

        std::cout << "The first " << size << " odds numbers in ascending way:" << std::endl;
        for (size_t i {}; i < size; ++i) {
                std::cout << *podds++ << ' ';
                if ((i + 1) % perline == 0) std::cout << std::endl;
        }

        std::cout << "\nThe first " << size << " odds numbers in descending way:" << std::endl;
        for (size_t i {}; i < size; ++i) {
                std::cout << *(--podds) << ' ';
                if ((i + 1) % perline == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
}
