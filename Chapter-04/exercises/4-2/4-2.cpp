/* Write another program that prompts for two integers to be entered. This time,
 * any negative number or zero is to be rejected. Next, check whether one of the (strictly positive)
 * numbers is an exact multiple of the other. For example, 63 is a multiple of 1, 3, 7, 9, 21, or 63.
 * Note that the user should be allowed to enter the numbers in any order. That is, it does not
 * matter whether the user enters the largest number first or the smaller one; both should work
 * correctly!
 */

#include <iostream>

int
main(void)
{
        int a {}, b {};

        std::cout << "Enter a number: ";
        std::cin >> a;
        std::cout << "Enter another number: ";
        std::cin >> b;

        if (a <= 0 || b <= 0) {
                std::cout << "Numbers cannot be less than or equal to zero (0)." << std::endl;
                return 1;
        }

        int gt {a > b ? a : b};
        int ls {a < b ? a : b};
        int check {a > b ? a % b : b % a};

        /* Notice that 0 is equivalent to false and any other value is true.
         * If check is true means that the numbers can't be exactly divided, otherwise they can. */
        std::cout << gt << " can"
                << (check ? "'t " : " ")
                << "be exactly divided by "
                << ls << std::endl;
}
