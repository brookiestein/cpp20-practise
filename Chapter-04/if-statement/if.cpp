#include <iostream>

int
main(void)
{
        int number {};
        std::cout << "Enter a number between 50 and 100: ";
        std::cin >> number;

        /* Because 'if' evaluates the condition to be different from zero, this
         * is the same as putting if (number != 0), but this way is also more explicit.
         */
        if (number)
                std::cout << "You've entered a number different from zero (0).\n";

        std::cout << "You've entered " << number << std::endl;

        if (number < 50) {
                std::cout << "By the way, that number is invalid because it's less than 50.\n";
        }

        if (number > 100) {
                std::cout << "By the way, that number is invalid because it's greater than 100.\n";
        }
}
