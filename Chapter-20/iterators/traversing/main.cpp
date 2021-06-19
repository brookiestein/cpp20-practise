/* There are a few ways in which you can traverse an iterator.
 * One of them is just to use a range-based for loop. */

#include <cstdint>
#include <iostream>
#include <vector>

int
main()
{
        std::vector<std::uint32_t> numbers;
        std::cout << "Enter a sequence of numbers terminating with -1:\n";
        std::int32_t input {};

        while (true) {
                std::cin >> input;
                if (input == -1) break;
                numbers.push_back(static_cast<std::uint32_t>(input));
        }

        std::cout << "The numbers you entered were:\n";
        for (const auto& number : numbers)
                std::cout << number << ' ';
        std::cout << std::endl;
}
