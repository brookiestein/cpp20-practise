/* Exercise 20-6. Another algorithm that is defined by the <numeric> module is the */
/* iota() algorithm, which you can use to fill a given range with values M, M+1, M+2, */
/* and so on. Use it to rework the fillVector_1toN() function of Ex20_10. */

#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& values);
template <typename T>
void removeEvenNumbers(std::vector<T>& numbers);

int
main()
{
        std::vector<unsigned> numbers (20);
        std::iota(numbers.begin(), numbers.end(), 1);
        removeEvenNumbers(numbers);
        printVector(numbers);
}

template <typename T> void
removeEvenNumbers(std::vector<T>& numbers)
{
        for (auto iter {numbers.begin()}; iter != numbers.end(); )
        {
                if (*iter % 2 == 0)
                        iter = numbers.erase(iter);
                else
                        ++iter;
        }
}

template <typename T> void
printVector(const std::vector<T>& values)
{
        for (size_t i {}; i < values.size(); ++i)
                std::cout << values[i] << ' ';
        std::cout << std::endl;
}
