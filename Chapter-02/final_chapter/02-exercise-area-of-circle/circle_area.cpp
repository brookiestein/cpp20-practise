/*
 * Write a program that will compute the area of a circle. The program should
 * prompt for the radius of the circle to be entered from the keyboard. Calculate the area using
 * the formula area = pi * radius * radius , and then display the result.
 */

#include <iostream>
#include <cmath>

#include "my_math.h"

int
main(void)
{
        /* I'm using a self-defined PI constant because
         * M_PI from <cmath> only has 5 numbers of mantissa.
         * I know that this shouldn't be so, but I'll fix it
         * when either gcc, clang, or whatever compiler has
         * support for C++20 to use the PI constant defined there.
         */
        /* const double PI {3.1415926535897932}; */
        double area {}, radius {};

        std::cout << "Enter the radius of the circle: ";
        std::cin >> radius;

        /* I could use radius * radius, but I wanted to practise
         * by using this function which was used in this book's chapter :)
         */
        area    = std::pow(radius, 2.0) * PI;
        std::cout << "The circle's area corresponding to "
                << radius << " of radius is " << area << std::endl;
        return 0;
}
