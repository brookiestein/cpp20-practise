/* Accessing local variables from a lambda by value. */

#include <iostream>
#include <vector>
#include <cmath>

template <typename T, typename Comparison> const T*
findOptimum(const std::vector<T>& values, Comparison compare);

int
main()
{
        std::vector<int> numbers { 42, 94, 77, 10, 14, 60 };
        int number_to_search_for {};

        std::cout << "Enter a number: ";
        std::cin >> number_to_search_for;

        std::size_t count {};
        auto nearer { [&] (int a, int b) {
                ++count;
                return std::abs(a - number_to_search_for) < std::abs(b - number_to_search_for);
        }};

        std::cout << "The nearest number to " << number_to_search_for
                << " is " << *findOptimum(numbers, nearer) << std::endl;
        std::cout << "The number of comparison that were performed is "
                << count << std::endl;
}

template <typename T, typename Comparison> const T*
findOptimum(const std::vector<T>& values, Comparison compare)
{
        if (values.empty()) return nullptr;

        const T* optimum { &values[0] };
        for (std::size_t i {1}; i < values.size(); ++i)
                if (compare(values[i], *optimum))
                        optimum = &values[i];
        return optimum;
}
