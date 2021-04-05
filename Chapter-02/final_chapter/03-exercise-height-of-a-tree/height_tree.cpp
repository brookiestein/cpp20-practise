/* For your birthday you’ve been given a long tape measure and an instrument that
 * measures angles (the angle between the horizontal and a line to the top of a tree, for instance).
 * If you know the distance, d , you are from a tree, and the height, h , of your eye when peering
 * into your angle-measuring device, you can calculate the height of the tree with the formula
 * h + d*tan(angle) . Create a program to read h in inches, d in feet and inches, and angle in
 * degrees from the keyboard, and output the height of the tree in feet.
 */

#include <iostream>
#include <cmath>

#include "my_math.h"

int
main(void)
{
        const double inches_per_foot {12.0};
        const double pi_degrees {180.0};
        double feet {}, inches {};

        std::cout << "Enter the distance from the tree in feet and inches: ";
        std::cin >> feet >> inches;
        const double distance {feet + inches / inches_per_foot};

        double angle {};
        std::cout << "Enter the angle of the top of the tree in degrees: ";
        std::cin >> angle;

        // Convert angle to radians because the trigonometric functions
        // of <cmath> operate with readians.
        angle *= PI / pi_degrees;

        double eye_height {};
        std::cout << "Enter your eye height from the ground in inches: ";
        std::cin >> eye_height;
        eye_height /= inches_per_foot;          // Convert to feet

        const double height {eye_height + distance * std::tan(angle)}; // Tree height in feet
        const unsigned height_feet {static_cast<unsigned>(height)};
        const unsigned height_inches {static_cast<unsigned>(std::round(inches_per_foot * (height - height_feet)))};

        std::cout << "\nThe height of the tree is " << height_feet << " feet "
                << height_inches << " inches." << std::endl;
}
