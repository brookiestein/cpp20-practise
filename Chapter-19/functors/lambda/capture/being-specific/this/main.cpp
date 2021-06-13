#include <iostream>
#include <optional>

#include "finder.hpp"

int
main()
{
        std::vector<double> numbers { 14.5, 73.74, 100.50, 3.141516 };
        Finder finder;
        double number_to_search_for {};
        std::cout << "Enter a number: ";
        std::cin >> number_to_search_for;
        finder.setNumberToSearchFor(number_to_search_for);

        auto nearer { finder.findNearer(numbers) };
        if (nearer)
                std::cout << "The nearest number to " << number_to_search_for
                        << " is " << nearer.value() << std::endl;
        else
                std::cout << "The vector is empty." << std::endl;
}
