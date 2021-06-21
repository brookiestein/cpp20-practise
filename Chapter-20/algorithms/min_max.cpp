#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int
main()
{
        std::vector numbers { 91, 18, 92, 22, 13, 43 };
        std::cout << "The minimum element is: "
                << *std::min_element(numbers.begin(), numbers.end())
                << std::endl;
        std::cout << "The maximum element is: "
                << *std::max_element(numbers.begin(), numbers.end())
                << std::endl;

        int number_to_search_for {};
        std::cout << "Enter a number: ";
        std::cin >> number_to_search_for;

        auto nearest { [number_to_search_for] (int x, int y) {
                return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
        }};

        /* Remember that we can decompose a std::pair with this C++17's _new_ syntax. */
        auto [nearer, furthest] { std::minmax_element(numbers.begin(), numbers.end(), nearest) };

        std::cout << "The nearest number to " << number_to_search_for << " is "
                << *nearer << std::endl;
        std::cout << "The furthest number to " << number_to_search_for << " is "
                << *furthest << std::endl;
}
