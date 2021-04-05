/* Create a program that prompts the user to enter an amount of money between
 * $0 and $10 (decimal places allowed). Any other value is to be rejected politely. Determine
 * how many quarters (25c), dimes (10c), nickels (5c), and pennies (1c) are needed to make up
 * that amount. For our non-American readers, one dollar ($) equals 100 cents (c). Output this
 * information to the screen and ensure that the output makes grammatical sense (for example, if
 * you need only one dime, then the output should be “1 dime” and not “1 dimes”).
 */

#include <iostream>

int
main(void)
{
        double money {};
        std::cout << "Enter an amount of money between $0 and $10: ";
        std::cin >> money;

        if (money < 0.0 || money > 10.0) {
                std::cout << "You've entered an invalid amount of money." << std::endl;
                return 1;
        }

        std::cout << "To have " << money << " we need " << (money / 0.25)
                << (money / 0.25 > 1 ? " quarters" : " quarter") << " of dollars."
                << std::endl;

        std::cout << "To have " << money << " we need " << (money / 0.10)
                << (money / 0.10 > 1 ? " dimers" : " dime") << " of dollars."
                << std::endl;

        std::cout << "To have " << money << " we need " << (money / 0.05)
                << (money / 0.05 > 1 ? " nickels" : " nickel") << " of dollars."
                << std::endl;

        std::cout << "To have " << money << " we need " << (money / 0.01)
                << (money / 0.01 > 1 ? " pennies" : " penny") << " of dollars."
                << std::endl;
}
