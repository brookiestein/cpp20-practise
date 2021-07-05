/* The compiler will use the more specific template constraint. */

#include <concepts>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <std::input_or_output_iterator Iter>
requires std::equality_comparable<Iter>
std::iter_difference_t<Iter> distanceBetween(Iter first, Iter last);

template <std::random_access_iterator Iter>
std::iter_difference_t<Iter> distanceBetween(Iter first, Iter last);

int
main()
{
        std::list l { 'a', 'b', 'c' };
        std::vector n { 1, 2, 3, 4, 5 };
        double d[] { 1.2, 3.4, 4.5 };

        std::cout << distanceBetween(std::begin(l), std::end(l)) << std::endl;
        std::cout << distanceBetween(std::begin(n), std::end(n)) << std::endl;
        std::cout << distanceBetween(std::begin(d), std::end(d)) << std::endl;
}

template <std::input_or_output_iterator Iter>
requires std::equality_comparable<Iter>
std::iter_difference_t<Iter> distanceBetween(Iter first, Iter last)
{
        std::cout << "Distance determined by linear traversal: ";
        std::iter_difference_t<Iter> result {};
        while (first != last) {
                ++first;
                ++result;
        }
        return result;
}

template <std::random_access_iterator Iter>
std::iter_difference_t<Iter> distanceBetween(Iter first, Iter last)
{
        std::cout << "Distance determined in constant time: ";
        return last - first;
}
