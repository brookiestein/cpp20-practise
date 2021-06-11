/* Function objects.
 * They're basically objects of a class that overrides the
 * function call operator, (). */

#include <iostream>
#include <vector>

template <typename T> using Comparison = bool (*)(const T&, const T&);

template <typename T>
class Less
{
public:
        bool operator()(const T& a, const T& b) const { return a < b; }
};

template <typename T> bool
greater(const T& a, const T& b) { return a > b; }

template <typename T> const T*
findOptimum(std::vector<T> values, Comparison<T> compare)
{
        if (values.empty()) return nullptr;

        const T* optimum { &values[0] };
        for (size_t i {1}; i < values.size(); ++i)
                if (compare(values[i], *optimum))
                        optimum = &values[i];
        return optimum;
}

int
main()
{
        Less<unsigned> less;
        std::cout << std::boolalpha;
        std::cout << "Is 5 less than 6? " << less(5, 6) << std::endl;
        std::cout << "Which one is greater between 5 and 6? "
                << *findOptimum({5, 6}, greater<unsigned>) << std::endl;
}
