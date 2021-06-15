#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>

#include "swap.hpp"
#include "counter.hpp"

template <typename T, typename Comparison>
void bubblesort(std::vector<T>& data, Comparison compare, Counter& counter)
{
        if (data.empty())
                return;
        for (size_t i {}; i < data.size() - 1; ++i)
                for (size_t j {}; j < data.size() - i - 1; ++j)
                        if (compare(data[j], data[j + 1])) {
                                swap(data, j, j + 1);
                                counter();
                        }
}

#endif
