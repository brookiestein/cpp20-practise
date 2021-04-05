/* Your body mass index (BMI) is your weight, w , in kilograms divided by the square
 * of your height, h , in meters ( w/(h*h) ). Write a program to calculate the BMI from a weight
 * entered in pounds and a height entered in feet and inches. A kilogram is 2.2 pounds, and a foot
 * is 0.3048 meters.
 */

#include <iostream>
#include <cmath>

int
main(void)
{
        const double inches_per_foot {12.0};
        const double kilograms_per_pound {2.2};
        const double meters_per_foot {0.3048};
        double pounds {}, feet {}, inches {};

        std::cout << "Enter your body weight in pounds: ";
        std::cin >> pounds;
        std::cout << "Enter your body height in feet and inches: ";
        std::cin >> feet >> inches;

        const double weight {pounds * kilograms_per_pound};
        //                                              converting to feet
        const double height {(feet * meters_per_foot) + ((inches / inches_per_foot) * meters_per_foot)};
        const double bmi {weight / std::pow(height, 2.0)};

        std::cout << "Your Body Mass Index (BMI) corresponding to "
                << pounds << " pounds and " << feet << "."
                << inches << " inches is " << bmi << std::endl;
}
