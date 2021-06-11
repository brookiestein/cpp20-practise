/* In this exercises I'll write a class FindOptimum that has
 * only two functions, its constructor and the function call operator. */

#ifndef FIND_OPTIMUM_H
#define FIND_OPTIMUM_H

#include <vector>

template <typename T> using Comparison = bool (*)(const T&, const T&);

template <typename T>
class FindOptimum
{
public:
        FindOptimum(const std::vector<T>& values, Comparison<T> compare_callback)
                : m_values {values}, m_compare {compare_callback}
        {}
        const T* operator()() const noexcept
        {
                if (m_values.empty()) return nullptr;

                const T* optimum { &m_values[0] };
                for (size_t i {1}; i < m_values.size(); ++i)
                        if (m_compare(m_values[i], *optimum))
                                optimum = &m_values[i];
                return optimum;
        }
private:
        std::vector<T> m_values;
        Comparison<T> m_compare;
};

#endif
