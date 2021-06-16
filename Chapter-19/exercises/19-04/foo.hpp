#ifndef FOO_HPP
#define FOO_HPP

#include <vector>

template <typename T, typename Verify>
std::vector<T>
foo(const std::vector<T>& data, Verify verify)
{
        std::vector<T> items;
        for (size_t i {}; i < data.size(); ++i)
                if (verify(data[i]))
                        items.push_back(data[i]);
        items.shrink_to_fit();
        return items;
}

#endif
