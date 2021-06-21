#include <iostream>
#include <string_view>
#include <vector>

std::vector<int> fillVector_1toN(const size_t N);
void printVector(std::string_view message, const std::vector<int>& numbers);
void removeEvenNumbers(auto& numbers);

int
main()
{
        const size_t num_of_items {20};
        auto numbers { fillVector_1toN(num_of_items) };
        printVector("Original vector", numbers);
        removeEvenNumbers(numbers);
        printVector("Numbers that were kept", numbers);
}

std::vector<int>
fillVector_1toN(const size_t N)
{
        std::vector<int> numbers;
        for (size_t i {1}; i <= N; ++i)
                numbers.push_back(i);
        return numbers;
}

void
printVector(std::string_view message, const std::vector<int>& numbers)
{
        std::cout << message << ": " << std::endl;
        for (size_t i {}; i < numbers.size(); ++i)
                std::cout << numbers[i] << ' ';
        std::cout << std::endl;
}

void
removeEvenNumbers(auto& numbers)
{
        for (auto iter {numbers.begin()}; iter != numbers.end(); ) {
                if (*iter % 2 == 0)
                        iter = numbers.erase(iter);
                else
                        ++iter;
        }
}
