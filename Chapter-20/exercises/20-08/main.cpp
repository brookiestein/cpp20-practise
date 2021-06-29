/* Exercise 20-8. erase() and erase_if() are not the only algorithms for which the */
/* remove-erase idiom is applicable. Another example is std::unique(), which is used */
/* to remove duplicates from a presorted range of elements. Write a little program that */
/* fills a vector<> with a considerably large amount of random integers between 0 and */
/* 10'000, sorts this sequence, removes the duplicates, and then prints out the amount of */
/* remaining elements. */

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int get_random_number(int max_limit);

int
main()
{
        std::vector<int> numbers (100);
        /* Get random numbers: */
        std::for_each(numbers.begin(), numbers.end(),
        [] (auto& n) { n = get_random_number(10'000); });

        /* Print them out: */
        size_t count {};
        std::cout << "Original sequence of numbers:\n";
        std::for_each(numbers.begin(), numbers.end(),
        [&count] (const auto& n) { std::cout << n << (++count % 20 == 0 ? '\n' : ' '); });
        std::cout << std::endl;

        /* Let's sort them and remove the duplicates numbers: */
        std::vector<int> duplicated;
        std::ranges::sort(numbers.begin(), numbers.end());
        auto last = std::unique(numbers.begin(), numbers.end());

        std::for_each(last, numbers.end(),
        [&duplicated] (const auto& n) { duplicated.push_back(n); });
        numbers.erase(last, numbers.end());

        /* Let's print them out again: */
        count = 0;
        std::cout << "\nUnique and sorted sequence of numbers:\n";
        std::for_each(numbers.begin(), numbers.end(),
        [&count] (const auto& n) { std::cout << n << (++count % 20 == 0 ? '\n' : ' '); });

        std::cout << "\nDuplicated numbers:\n";
        std::for_each(duplicated.begin(), duplicated.end(),
        [] (const auto& n) { std::cout << n << ' '; });
        std::cout << std::endl;
}

int
get_random_number(int max_limit)
{
        std::random_device random;
        std::default_random_engine random_engine { random() };
        std::uniform_int_distribution distribution (0, max_limit);
        return distribution(random_engine);
}
