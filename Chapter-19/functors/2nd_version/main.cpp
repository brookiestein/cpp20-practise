/* In this exercises I'll write a class FindOptimum that has
 * only two functions, its constructor and the function call operator. */

#include <iostream>

#include "find_optimum.hpp"

template <typename T> bool less(const T& a, const T& b) { return a < b; };
template <typename T> bool greater(const T& a, const T& b) { return a > b; };

int
main()
{
        std::vector<unsigned> numbers { 99, 43, 54, 95, 14, 7 };
        FindOptimum<unsigned> find_less { numbers, less };
        FindOptimum<unsigned> find_greater { numbers, greater };

        std::cout << "Lesser number is: " << *find_less() << std::endl;
        std::cout << "Greatest number is: " << *find_greater() << std::endl;
}
