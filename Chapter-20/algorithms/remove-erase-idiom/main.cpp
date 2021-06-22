#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> void showVector(const std::vector<T>& values);

auto
fillVector_1toN(const size_t N)
{
        std::vector<int> numbers;
        for (size_t i {}; i < N; ++i)
                numbers.push_back(i + 1);
        return numbers;
}

int
main()
{
        auto numbers { fillVector_1toN(20) };

        /* Remove-and-erase idiom consists in the use of std::remove(), or std::remove_if()
         * functions in order to std::move() all the elements that are going to be removed
         * at the end of the container, getting an iterator to the first element to be removed.
         * As way of we can just erase() all of them. */

        std::cout << "The initial vector:" << std::endl;
        showVector(numbers);

        /* std::move() all elements to be removed at the end: */
        auto first_to_erase { std::remove_if(numbers.begin(), numbers.end(),
                        [] (const auto& n) { return n % 2 == 1; }
        )};

        /* And just erase() them! */
        numbers.erase(first_to_erase, numbers.end());

        std::cout << "The vector after removing odd numbers:" << std::endl;
        showVector(numbers);
}

template <typename T> void
showVector(const std::vector<T>& values)
{
        for (size_t i {}; i < values.size(); ++i)
                std::cout << values[i] << ' ';
        std::cout << std::endl;
}
