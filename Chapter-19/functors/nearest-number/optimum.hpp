/* In this exercises I'll write a class FindOptimum that has
 * only two functions, its constructor and the function call operator. */

#ifndef OPTIMUM_H
#define OPTIMUM_H

#include <vector>

#include "nearest.hpp"

template <typename T, typename Comparison>
class FindOptimum
{
public:
        FindOptimum(const std::vector<T>& values, Comparison compare)
                : m_values {values}, m_compare {compare}
        {}
        const T* operator()() const noexcept
        {
                if (m_values.empty()) return nullptr;

                const T* optimum { &m_values[0] };
                for (std::size_t i {1}; i < m_values.size(); ++i)
                        if (m_compare(m_values[i], *optimum))
                                optimum = &m_values[i];
                return optimum;
        }
private:
        std::vector<T> m_values;
        Comparison m_compare;
};

#endif
