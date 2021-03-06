#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> fillVector_1toN(const size_t size);
void showVector(const std::vector<int>& numbers);

int
main()
{
        auto numbers { fillVector_1toN(20) };
        std::vector<int> even;
        std::copy_if(numbers.begin(), numbers.end(),
                        std::back_inserter(even),
                        [] (int n) {
                                return n % 2 == 0;
        });


        std::cout << "This is the original vector:\n";
        showVector(numbers);
        std::cout << "\nThese are the even numbers that were extracted from the vector:\n";
        showVector(even);
}

std::vector<int>
fillVector_1toN(const size_t size)
{
        std::vector<int> numbers;
        for (size_t i {}; i < size; ++i)
                numbers.push_back(i + 1);
        return numbers;
}

void
showVector(const std::vector<int>& numbers)
{
        for (const auto& n : numbers)
                std::cout << n << ' ';
        std::cout << std::endl;
}
