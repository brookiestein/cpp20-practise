#include <iostream>

int
main()
{
        const double pi {3.141592653589793}; // Circumference of a pizze divided by its diameter.
        double a {0.2}; // Thickness of proper New York-style pizza (in inches)
        double z {9}; // Radius of larga New York-style pizza (in inches)
        double volume {}; // Volume of pizza - to be calculated
        volume = pi*z*z*a;
        std::cout << "The pizza's volume is " << volume << std::endl;
        return 0;
}
