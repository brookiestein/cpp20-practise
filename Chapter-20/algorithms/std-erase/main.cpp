/* The remove-erase idiom is great, but it's error-prone, so
 * in C++ almost all modules have introduced a std::erase() function
 * (except <array>)to do that work better. */

#include <algorithm>
#include <iostream>
#include <vector>

auto
fillVector_1toN(const size_t N)
{
        std::vector<int> numbers;
        for (size_t i {}; i < N; ++i)
                numbers.push_back(i + 1);
        return numbers;
}

template <typename T> void
showVector(const std::vector<T>& values)
{
        for (size_t i {}; i < values.size(); ++i)
                std::cout << values[i] << ' ';
        std::cout << std::endl;
}

int
main()
{
        auto numbers { fillVector_1toN(20) };
        std::cout << "Initial vector:\n";
        showVector(numbers);
        /* Remove all even numbers. */
        std::erase_if(numbers, [] (auto& n) { return n % 2 == 0; });
        std::cout << "Vector after removing even numbers:\n";
        showVector(numbers);
}
