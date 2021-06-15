/* Testing the performance of the quick sort and bubble sort algorithms. */

#include <iostream>
#include <vector>
#include <string_view>

#include "quicksort.hpp"
#include "bubblesort.hpp"
#include "counter.hpp"

template <typename T>
void show(const std::vector<T>& data, size_t perline = 5,
                std::string_view message = "Values:");

int
main()
{
        const std::vector<int> original { 14, 93, 44, 76, 99, 37, 54 };
        auto to_order_with_bubble_sort { original };
        auto to_order_with_quick_sort { original };
        Counter counter;

        show(to_order_with_bubble_sort, original.size(), "Original vector (bubble sort):");
        bubblesort(to_order_with_bubble_sort, [] <typename T> (T& a, T& b) {
                return a > b;
        }, counter);
        show(to_order_with_bubble_sort, original.size(), "Sorted vector (bubble sort):");

        std::cout << "Number of comparisons: " << counter.getCount() << "\n\n";
        counter.reset();

        show(to_order_with_quick_sort, original.size(), "Original vector (quick sort):");
        quicksort(to_order_with_quick_sort, [] <typename T> (const T& a, const T& b) {
                return a < b;
        }, counter);
        show(to_order_with_quick_sort, original.size(), "Sorted vector (quick sort):");
        std::cout << "Number of comparisons: " << counter.getCount() << std::endl;
}

template <typename T>
void show(const std::vector<T>& data, size_t perline, std::string_view message)
{
        std::cout << message << std::endl;
        size_t count {};
        for (size_t i {}; i < data.size(); ++i)
                std::cout << data[i] << (!++count % perline ? '\n' : ' ');
        std::cout << std::endl;
}
