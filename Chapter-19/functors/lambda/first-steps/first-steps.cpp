/* First steps in Lambda expressions. */

#include <iostream>
#include <vector>

template <typename T, typename Comparison> const T* findOptimum(const std::vector<T>& values, Comparison compare);

int
main()
{
        std::vector<unsigned> numbers { 43, 95, 115, 27, 55 };
        std::cout << "Greater number is: "
                << *findOptimum(numbers, [] (int a, int b) { return a > b; })
                << std::endl;
}

template <typename T, typename Comparison> const T*
findOptimum(const std::vector<T>& values, Comparison compare)
{
        if (values.empty()) return nullptr;

        const T* optimum { &values[0] };
        for (size_t i {1}; i < values.size(); ++i)
                if (compare(values[i], *optimum))
                        optimum = &values[i];
        return optimum;
}
