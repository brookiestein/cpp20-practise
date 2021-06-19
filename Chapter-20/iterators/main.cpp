/* We can work with iterators just like if they were a pointer.
 * Let's see that in practice. */
#include <iostream>
#include <vector>

int
main()
{
        std::vector<char> letters { 'B', 'r', 'a', 'y', 'a', 'n' };
        auto iter { letters.begin() };

        while (*iter)
                std::cout << *iter++;
        std::cout << std::endl;
}
