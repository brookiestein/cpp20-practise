/* Test whether a number, entered by the user, is either odd or even. */
#include <iostream>

int
main(void)
{
        long number {};
        std::cout << "Enter a number: ";
        std::cin >> number;

        if (number % 2) {
                std::cout << "The number is odd.";
        } else {
                std::cout << "The number is even.";
        }

        std::cout << std::endl;
}
