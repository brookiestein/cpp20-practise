#include <iostream>
#include <vector>

int
main()
{
        std::vector numbers { 1, 2, 4, 5 }; /* Deduced type: std::vector<int> */
        auto iter { numbers.begin() + 2 }; /* Deduced type: std::vector<int>::iterator */
        iter = numbers.insert(iter, 3);

        for (size_t i {}; i < numbers.size(); ++i)
                std::cout << numbers[i] << ' ';
        std::cout << std::endl;

        std::vector more_numbers { 6, 7, 8, 9 };
        iter = numbers.insert(numbers.end(), more_numbers.begin(), more_numbers.end());
        for (size_t i {}; i < numbers.size(); ++i)
                std::cout << numbers[i] << ' ';
        std::cout << std::endl;
}
