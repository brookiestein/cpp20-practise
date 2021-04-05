#include <iostream>
#include <vector>
#include <span>

int
main()
{
        const std::vector<int> numbers { 4, 8, 15, 16, 23, 42 };
        /* std::span<int> sp { numbers }; /1* This won't work, because it can't be created from a const vector or any other allowed container. *1/ */
        std::span<const int> sp { numbers };
        for (auto n : sp)
                std::cout << n << ' ';
        std::cout << std::endl;
}
