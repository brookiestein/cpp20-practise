/* Capture one or more specific variables from within the lambda. */

#include <iostream>

int
main()
{
        double x {};
        double y {};

        std::cout << "Enter a number: ";
        std::cin >> x;
        std::cout << "Enter another number: ";
        std::cin >> y;

        auto greater { [&x] (double y) { return x++ > y; } };

        std::cout << std::boolalpha
                << (greater(y) ? x : y)
                << " is greater.\n"
                << "x's value after checking which of them is the greatest: "
                << x << std::endl;
}
