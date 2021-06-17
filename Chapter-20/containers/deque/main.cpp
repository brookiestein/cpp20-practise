#include <iostream>
#include <deque>

int
main()
{
        std::deque<unsigned> numbers;
        numbers.push_back(2);
        numbers.push_back(4);
        numbers.push_back(1);

        /* Demonstrating that a deque is a random access container. */
        numbers[2] = 3;

        std::cout << "There are " << numbers.size()
                << " values in my deque." << std::endl;
        /* Like other containers, a deque is a range. */
        for (const auto& value : numbers)
                std::cout << value << ' ';
        std::cout << std::endl;
}
