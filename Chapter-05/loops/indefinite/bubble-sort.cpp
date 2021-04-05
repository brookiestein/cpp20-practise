#include <iostream>

int
main(void)
{
        const size_t size {1'000}; /* Max size of the array. */
        double numbers[size] {};
        size_t count {};

        while (true) {
                double input {};
                std::cout << "Enter a non-zero value or zero to end: ";
                std::cin >> input;

                if (input == 0)
                        break;

                numbers[count] = input;

                if (++count == size) {
                        std::cout << "Sorry, but I can only store " << size
                                << " values." << std::endl;
                        break;
                }
        }

        if (count == 0) {
                std::cout << "Nothing to sort. Program terminated." << std::endl;
                return 0;
        }

        std::cout << "Starting sort..." << std::endl;
        while (true) {
                bool swapped {}; /* false by default. */

                for (size_t i {}; i < count - 1; ++i) {
                        if (numbers[i] > numbers[i + 1]) {
                                const auto tmp {numbers[i]};
                                numbers[i]      = numbers[i + 1];
                                numbers[i + 1]  = tmp;
                                swapped = true;
                        }
                }

                /* Nothing was done, so it's sorted. */
                if (!swapped)
                        break;
        }

        const size_t perline {10};
        size_t n {};
        std::cout << "Elements in ascending order:" << std::endl;
        for (size_t i {}; i < count; ++i) {
                std::cout << numbers[i] << ", ";
                if (++n == perline || i == (count - 1)) {
                        std::cout << "\b\b" << std::endl;
                        n = 0;
                }
        }
}
