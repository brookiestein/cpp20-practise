/* This program will calculate the average of temperatures entered
 * by the user.
 */

#include <iostream>
#include <cctype>

int
main(void)
{
        char reply {}; /* Determines whether the loop continues or not. */
        double temperature {};
        double total {};
        unsigned int count {};

        do {
                std::cout << "Enter a temperature reading: ";
                std::cin >> temperature;
                total += temperature;
                ++count;

                std::cout << "Would you like to add another temperature? ";
                std::cin >> reply;
        } while (std::tolower(reply) == 'y');

        std::cout << "The temperature average is " << (total / count) << '\n';
}
