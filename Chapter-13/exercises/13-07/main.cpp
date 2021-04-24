/* Exercise 13-7. Implement a class called Rational that represents a rational number. */
/* A rational number can be expressed as the quotient or fraction n / d of two integer */
/* numbers, an integral numerator n , and a nonzero, positive integral denominator d . */
/* Do not worry about enforcing that the denominator is nonzero, though. That’s not the */
/* point of the exercise. Definitely create an operator that allows a rational number to */
/* be streamed to std::cout . Beyond that, you are free to choose how many and which */
/* operators you add. You could create operators to support multiplication, addition, */
/* subtraction, division, and comparison of two Rational numbers and of Rational */
/* numbers and integers. You could create operators to negate, increment, or decrement */
/* Rational numbers. And what about converting to a float or a double ? There really */
/* is a huge amount of operators you could define for Rational s. The Rational class */
/* in our model solution supports well over 20 different operators, many overloaded */
/* for multiple types. Perhaps you come up with even more rational (as in sensible) */
/* operators for your Rational class? Do not forget to create a program to test that */
/* your operators actually work. */

#include <iostream>

#include "rational.h"

int
main()
{
        Rational rational_1 {1, 2};
        Rational rational_2 {3, 4};

        std::cout << "Rational 1: " << rational_1 << std::endl;
        std::cout << "Rational 2: " << rational_2 << std::endl;
        std::cout << std::endl;

        std::cout << "Rational 1++: " << rational_1++ << std::endl;
        std::cout << "Rational 1: " << rational_1 << std::endl;
        std::cout << "Rational --2: " << --rational_2 << std::endl;
}
