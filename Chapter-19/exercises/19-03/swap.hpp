#ifndef SWAP_HPP
#define SWAP_HPP

#include <vector>

template <typename T>
void swap(std::vector<T>& data, size_t first, size_t second)
{
        auto temp { data[first] };
        data[first] = data[second];
        data[second] = temp;
}

#endif
