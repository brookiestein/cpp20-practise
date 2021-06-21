#include <iostream>
#include <vector>

template <typename T> void printVector(const std::vector<T>& values);

int
main()
{
        std::vector numbers { 1, 2, 4, 5 };
        auto iter { numbers.insert(numbers.begin() + 2, 3) }; /* numbers == 1, 2, 3, 4, 5 */
        printVector(numbers);
        iter = numbers.erase(iter + 1, numbers.end()); /* numbers == 1, 2, 3 */
        printVector(numbers);
}

template <typename T>
void printVector(const std::vector<T>& values)
{
        for (size_t i {}; i < values.size(); ++i)
                std::cout << values[i] << ' ';
        std::cout << std::endl;
}
