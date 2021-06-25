#include <iostream>
#include <ranges>

bool isEven(int n) { return n % 2 == 0; }
int squared(int n) { return n * n; }

int
main()
{
        using namespace std::ranges::views;
        for (auto i : iota(1, 10))
                std::cout << i <<  ' ';
        std::cout << std::endl;

        for (auto i : iota(1, 1'000) | filter(isEven) | transform(squared)
                                     | drop(2) | take(5))
        std::cout << std::endl;
}
