/* Exercise 20-7. Speaking of Ex20_10, you of course know that instead of filling a vector */
/* with numbers from 1 to N, you could have used an appropriate view. And instead */
/* of removing elements from that vector, you could have used another view. Rework */
/* Ex20_10 to work with views. */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int
main()
{
        using namespace std::ranges::views;
        std::vector<unsigned> numbers;
        for (unsigned i : iota(1, 21) | filter([] (const auto& n) { return n % 2 == 1; }) | reverse)
                numbers.push_back(i);
        std::for_each(numbers.begin(), numbers.end(),
                [] (const auto& n) { std::cout << n << ' '; });
        std::cout << std::endl;
}
