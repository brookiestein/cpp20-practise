/* Using the std::function template of the functional header (module in C++ 20) */

#include <iostream>
#include <functional>
#include <cmath>

bool less(double x, double y) { return x < y; }

int
main()
{
        double x {10};
        double y {15};
        std::function<bool(double, double)> compare {less};

        std::cout << std::boolalpha;
        std::cout << x << " < " << y << ": " << compare(x, y) << std::endl;

        compare = std::greater<>{};
        std::cout << x << " > " << y << ": " << compare(x, y) << std::endl;

        double number_to_search_for {};
        std::cout << "Enter a number: ";
        std::cin >> number_to_search_for;

        compare = [number_to_search_for] (double x, double y) -> bool {
                return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
        };

        std::cout << number_to_search_for << " nearer to " << x << " than "
                << y << ": " << compare(x, y) << std::endl;
}
