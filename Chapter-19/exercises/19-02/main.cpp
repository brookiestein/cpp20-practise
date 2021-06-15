/* To solve this exercise, I've used the bubble sort algorithm.
 * I know this is not the more efficient sort algorithm, though. */

#include <cctype>
#include <cmath>
#include <iostream>
#include <string_view>
#include <vector>

template <typename T> void swap(T& a, T& b);
template <typename T, typename Comparison> void sort(std::vector<T>& values, Comparison compare);
template <typename T> void show(const std::vector<T>& values,
                std::size_t perline = 5, std::string_view message = "Sorted vector:");

int
main()
{
        std::vector<int> numbers { 17, 94, 43, 25, 79, 85, 12, 3, 1'500 };
        show(numbers, 5, "Original int vector:");

        sort(numbers, [] <typename T> (T& a, T& b) -> bool {
                return a < b;
        });

        show(numbers, 5);

        std::vector<char> chars { 'J', 'b', 'Z', 'k', 'l', 'R', 'O' };
        show(chars, chars.size(), "Original char vector:");

        sort(chars, [] (char a, char b) -> bool {
                return std::tolower(a) > std::tolower(b);
        });

        show(chars, chars.size());

        std::vector<double> doubles { 14.76, 3.14, -55.14, -100.97, 60 };
        show(doubles, doubles.size(), "Original vector:");

        sort(doubles, [] (double a, double b) mutable -> bool {
                if (a < 0.0)
                        a = std::abs(a);
                if (b < 0.0)
                        b = std::abs(b);
                return a > b;
        });

        show(doubles);
}

template<typename T>
void
swap(T& a, T& b)
{
        T temp { a };
        a = b;
        b = temp;
}

template <typename T, typename Comparison>
void
sort(std::vector<T>& numbers, Comparison compare)
{
        if (numbers.empty()) {
                std::cout << "Vector's empty. Nothing to sort." << std::endl;
                return;
        }

        for (std::size_t i {0}; i < numbers.size() - 1; ++i)
                for (std::size_t j {}; j < numbers.size() - i - 1; ++j)
                        if (compare(numbers[j], numbers[j + 1]))
                                swap(numbers[j], numbers[j + 1]);
}

template <typename T>
void
show(const std::vector<T>& values, std::size_t perline, std::string_view message)
{
        std::cout << message << std::endl;
        std::size_t count {};
        for (std::size_t i {}; i < values.size(); ++i)
                std::cout << values[i] << (!++count % perline ? '\n' : ' ');
        std::cout << std::endl;
}
