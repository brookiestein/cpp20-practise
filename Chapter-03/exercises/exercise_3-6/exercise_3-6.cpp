/* We’ll conclude with one more exercise for puzzle fans (and exclusively so).
 * Write a program that prompts for two integer values to be entered and store them in integer
 * variables, a and b , say. Swap the values of a and b without using a third variable. Output the
 * values of a and b .
 * Hint: This is a particularly tough nut to crack. To solve this puzzle, you exclusively need one
 * single compound assignment operator.
 */

#include <iostream>

int
main(void)
{
        int a {}, b {};

        std::cout << "Enter a first number: ";
        std::cin >> a;
        std::cout << "Enter a second number: ";
        std::cin >> b;

        a ^= b;
        b ^= a;
        a ^= b;

        std::cout << "A: " << a << '\n' << "B: " << b << std::endl;
}
