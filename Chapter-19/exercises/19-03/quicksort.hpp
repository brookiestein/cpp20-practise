#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>

#include "swap.hpp"
#include "counter.hpp"

template <typename T, typename Comparison>
void quicksort(std::vector<T>& data, Comparison compare, Counter& counter)
{
        if (!data.empty())
                quicksort(data, compare, counter, 0, data.size() - 1);
}

template <typename T, typename Comparison>
void quicksort(std::vector<T>& data, Comparison compare,
                Counter& counter, std::size_t start, std::size_t end)
{
        /* Start index must be less than end index for 2 or more elements. */
        if (!(start < end))
                return;

        /* Choose middle address to partition set. */
        swap(data, start, (start + end) / 2); /* Swap middle element with start element. */

        /* Check data against chosen element. */
        std::size_t current {start};
        for (std::size_t i {start + 1}; i <= end; ++i)
                if (compare(data[i], data[start])) {
                        swap(data, ++current, i); /* Yes, so swap to the left. */
                        counter();
                }
        swap(data, start, current); /* Swap chosen and last swapped elements. */

        if (current > start) quicksort(data, compare, counter, start, current - 1);
        if (end > current + 1) quicksort(data, compare, counter, current + 1, end);
}

#endif
