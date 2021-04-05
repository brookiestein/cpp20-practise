/* Create a program that prompts for input of a number (nonintegral numbers are
 * allowed) between 1 and 100. Use a nested if , first to verify that the number is within this
 * range and then, if it is, to determine whether it is greater than, less than, or equal to 50. The
 * program should output information about what was found.
 */

#include <iostream>

int
main(void)
{
        double num {};
        std::cout << "Enter a number between 1 and 100: ";
        std::cin >> num;

        if (num >= 1.0 && num <= 100.0) {
                std::cout << "The entered number is ";
                if (num < 50.0) {
                        std::cout << "less than";
                } else if (num == 50.0) {
                        std::cout << "equals to";
                } else {
                        std::cout << "greater than";
                }
                std::cout << " fifty (50).";
        } else {
                std::cout << "The entered number is not in the allowed range.";
        }

        std::cout << '\n';
}
