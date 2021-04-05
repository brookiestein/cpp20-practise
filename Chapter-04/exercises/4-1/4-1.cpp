/* Write a program that prompts for two integers to be entered and then uses an
 * if - else statement to output a message that states whether the integers are the same.
 */

#include <iostream>

int
main(void)
{
        int a {}, b {};

        std::cout << "Enter a number (a): ";
        std::cin >> a;
        std::cout << "Enter another number (b): ";
        std::cin >> b;

        if (a == b) {
                std::cout << "Both a as b are the same.";
        } else {
                std::cout << "a and b are different.";
        }

        std::cout << '\n';
}
