/* The set container does not allow to have an element twice or that appears
 * more times. */

#include <iostream>
#include <unordered_set>

template <typename T>
void printSet(const std::unordered_set<T> values);

int
main()
{
        std::unordered_set<unsigned> numbers;
        numbers.insert(1);
        numbers.insert(5);
        numbers.insert(3);
        numbers.insert(2);
        numbers.insert(4);
        numbers.insert(3);
        numbers.insert(5);
        numbers.insert(5);

        printSet(numbers);

        std::cout << "Number 1 occurs " << numbers.count(1)
                << " time(s) in the set." << std::endl;
        numbers.erase(5);
        printSet(numbers);
        numbers.clear();
        printSet(numbers);
}

template <typename T>
void printSet(const std::unordered_set<T> values)
{
        const size_t size { values.size() };
        std::cout << "There " << (size == 1 ? "is " : "are ")
                << size << (size == 1 ? " value " : " values ")
                << "in the set." << std::endl;
        for (const auto& value : values)
                std::cout << value << ' ';
        std::cout << std::endl;
}
