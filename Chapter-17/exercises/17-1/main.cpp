#include <iostream>

#include "array.hpp"

int
main()
{
        Array<unsigned> numbers;

        for (std::size_t i {}; i < 5; ++i)
                numbers.push_back(i + 1);

        for (std::size_t i {}; i < numbers.size(); ++i)
                std::cout << numbers[i] << ' ';
        std::cout << std::endl;
}
