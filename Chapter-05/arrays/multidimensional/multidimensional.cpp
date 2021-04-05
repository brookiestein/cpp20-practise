#include <iostream>
#include <array>

int
main(void)
{
        int values[2][3] {};

        /* Filling the array. */
        for (size_t i {}; i < std::size(values); i++) {
                for (size_t j {}; j < std::size(values[i]); j++) {
                        std::cout << "Enter a number: ";
                        std::cin >> values[i][j];
                }
        }

        /* Printing the values. */
        for (size_t i {}; i < std::size(values); i++) {
                for (size_t j {}; j < std::size(values[i]); j++) {
                        std::cout << values[i][j] << " ";
                }
                std::cout << std::endl; /* Jump to another column. */
        }
}
