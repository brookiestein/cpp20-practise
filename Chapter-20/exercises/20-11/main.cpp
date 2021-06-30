/* Exercise 20-11. Write a function that determines whether a given integer is a prime */
/* number. If you’re lost on how to do this, you can always distill a prime test from */
/* Ex6_05. Now use this function to print out the first 100 prime numbers in reverse order. */
/* Do so without the use of any container. */
/* Hint: You already used the iota(from,to) range factory, but iota(from) is valid as */
/* well. The latter factory call produces a view that, conceptually, contains an infinite */
/* amount of consecutive values, starting with from. Because a view’s elements are */
/* only generated lazily, having a view that is, at least conceptually, infinitely large is no */
/* problem. Just make sure you do not attempt to exhaustively read all elements of such a */
/* view because that might take a while… */

#include <iostream>
#include <ranges>

int
main()
{
        using namespace std::ranges::views; /* To avoid a bit of pain! */
        size_t count {};

        auto is_prime = [] (const auto& n) -> bool {
                size_t count {};
                for (size_t i {1}; i <= n; ++i) {
                        if (n % i == 0)
                                ++count;
                        if (count > 2)
                                return false;
                }
                return true;
        };

        for (int i : iota(1) | filter(is_prime) | take(100) | reverse) {
                std::cout << i << (++count % 20 == 0 ? '\n' : ' ');
                if (count == 100)
                        break;
        }
}
