/*
 * Write a program that determines, using only the conditional operator,
 * if an integer that is entered has a value that is 20 or less, is greater
 * than 20 but not greater than 30, is greater than 30 but not exceeding 100,
 * or is greater than 100.
 */

#include <iostream>

int
main(void)
{
        int num {};
        std::cout << "Enter a number: ";
        std::cin >> num;

        std::cout << "The entered number is "
                << (num < 20 ? "less than 20." :
                (num == 20 ? "equals to 20." : (num > 20 && num < 30 ? "greater than 20, but less than 30." :
                (num > 30 && num < 100 ? "greater than 30, but less than 100." :
                (num == 30 ? "equals to 30." : (num == 100 ? "equals to 100." : "greater than 100."))))))
                << std::endl;
}
