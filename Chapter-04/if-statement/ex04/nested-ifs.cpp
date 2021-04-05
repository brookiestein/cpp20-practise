/* Verifying if a letter entered by the user is either upper, lower,
 * any of these.
 */

#include <iostream>

int
main(void)
{
        char letter {};
        std::cout << "Enter a letter: ";
        std::cin >> letter;

        if (letter >= 'A') {
                if (letter <= 'Z') {
                        std::cout << "You've entered an uppercase letter.\n";
                        return 0;
                }
        }

        if (letter >= 'a') {
                if (letter <= 'z') {
                        std::cout << "You've entered a lowercase letter.\n";
                        return 0;
                }
        }

        std::cout << "You didn't enter a letter." << std::endl;
}
