/* Sorting numbers parallelly. */

#include <algorithm>
#include <execution>
#include <cstdint>
#include <iostream>
#include <string_view>
#include <ranges>
#include <vector>

std::vector<unsigned int> fillVector_1toN(const size_t N);
template <typename T>
void printVector(const std::vector<T>& values,
                size_t perline = 20, std::string_view message = "Values:");

int
main()
{
        /* Maybe I'm exaggerating? :P */
        auto numbers { fillVector_1toN(30) };
        printVector(numbers);

        std::cout << "Sorting in descending mode..." << std::endl;
        /* Using parallelism: */
        /* std::sort(std::execution::par, numbers.begin(), numbers.end(), */
        /*         [] (auto& left, auto& right) { return left > right; }); */
        std::ranges::sort(numbers, std::greater<>{});
        printVector(numbers, 20, "Numbers in descending mode:");
}

std::vector<unsigned int>
fillVector_1toN(const size_t N)
{
        std::cout << "Adding numbers..." << std::endl;
        std::vector<unsigned int> values (N);
        unsigned int i {};

        std::for_each(std::execution::par,
                std::begin(values), std::end(values),
                [i] (auto& n) mutable { n = ++i; });

        std::cout << "\nNumbers added." << std::endl;
        return values;
}

template <typename T> void
printVector(const std::vector<T>& values, size_t perline, std::string_view message)
{
        std::cout << message << std::endl;
        size_t count {};
        for (size_t i {}; i < values.size(); ++i) {
                std::cout << values[i] << ' ';
                if (++count == perline) {
                        std::cout << std::endl;
                        count = 0;
                }
        }
        std::cout << std::endl;
}
