/* Exercise 20-4. Research the partition() algorithms and use one to reimplement the */
/* removeEvenNumbers() function of either Ex20_10 or Ex20_14. */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int
main()
{
        std::vector<unsigned> numbers (20);
        std::iota(numbers.begin(), numbers.end(), 1);

        auto iter { std::partition(numbers.begin(), numbers.end(),
                [] (const auto& n) { return n % 2 == 1; }) };

        numbers.erase(iter, numbers.end());
        std::for_each(numbers.begin(), numbers.end(),
                [] (const auto& n) { std::cout << n << ' '; });
        std::cout << std::endl;
}
