/* We can insert elements into a container, even using raw pointers
 * as iterators. */

#include <iostream>
#include <iterator>
#include <vector>

template <typename T> void showVector(const std::vector<T>& values);

int
main()
{
        std::vector numbers { 1, 2, 3, 4, 5 };
        int more_numbers[] { 6, 7, 8 };
        int even_more_numbers[] { 9, 10 };

        /* Inserting using the array itself as the beginning of
         * the inserting operation, and the size of itself as the end. */
        numbers.insert(numbers.end(), more_numbers, more_numbers + std::size(more_numbers));

        /* Now inserting using the std::begin, and std::end functions from <iterator>. */
        numbers.insert(numbers.end(), std::begin(even_more_numbers), std::end(even_more_numbers));
        showVector(numbers);
}

template <typename T>
void
showVector(const std::vector<T>& values)
{
        for (size_t i {}; i < values.size(); ++i)
                std::cout << values[i] << ' ';
        std::cout << std::endl;
}
