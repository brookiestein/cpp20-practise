/* Exercise 20-5. Not all Standard Library algorithms are defined by the <algorithms> */
/* module. Some are defined by the <numeric> module as well. One such example is */
/* accumulate(). Research this algorithm and use it to implement an algorithm-like */
/* function template that computes the average of a given iterator range. Exercise your */
/* newly implemented template with a little test program. */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int
main()
{
        std::vector<unsigned> numbers (20);
        std::iota(numbers.begin(), numbers.end(), 1);
        auto sum = std::accumulate(numbers.begin(), numbers.end(), 0);
        auto avg = sum / numbers.size();
        std::cout << "The sum is: " << sum << std::endl;
        std::cout << "The average is: " << avg << std::endl;
}
