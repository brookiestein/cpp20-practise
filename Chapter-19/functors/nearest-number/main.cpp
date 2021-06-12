#include <iostream>
#include <vector>

#include "nearest.hpp"
#include "optimum.hpp"


int
main()
{
        std::vector<int> numbers { 93, 67, 7, 1'000, 44 };
        int search_for {};
        std::cout << "Enter a number: ";
        std::cin >> search_for;
        FindOptimum<int, Nearest> finder { numbers, Nearest { search_for } };
        std::cout << "The nearest number to " << search_for
                << " is " << *finder() << std::endl;
}
