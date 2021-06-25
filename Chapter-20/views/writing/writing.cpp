#include <iostream>
#include <ranges>
#include <vector>

int
main()
{
        std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        auto isEven = [] (int n) -> bool { return n % 2 == 0; };

        for (int& i : numbers | std::ranges::views::filter(isEven))
                i *= i;

        for (const int& i : numbers)
                std::cout << i << ' ';
        std::cout << std::endl;
}
