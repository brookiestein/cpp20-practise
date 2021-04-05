/* Write a program that declares and initializes an array with the first 50 odd (as in
 * not even) numbers. Output the numbers from the array ten to a line using pointer notation and
 * then output them in reverse order, also using pointer notation.
 */

#include <iostream>

int
main(void)
{
        const size_t size {50};
        unsigned int odds[size] {};
        size_t count {};
        size_t i {1};

        for (;;) {
                if (i % 2 != 0)
                        odds[count++] = i;
                if (count == size)
                        break;
                i++;
        }

        count = 0;
        std::cout << "In ascending way:" << std::endl;
        for (size_t i {}; i < size; ++i) {
                std::cout << *(odds + count++) << ' ';
                if ((i + 1) % 10 == 0) std::cout << std::endl;
        }

        std::cout << '\n' << "In descending way:" << std::endl;
        for (size_t i {}; i < size; ++i) {
                std::cout << *(odds + (--count)) << ' ';
                if ((i + 1) % 10 == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
}
