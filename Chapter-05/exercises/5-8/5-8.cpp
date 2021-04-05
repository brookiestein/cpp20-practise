/* The famous Fibonacci series is a sequence of integers with the first two values as
 * 1 and the subsequent values as the sum of the two preceding values. So, it begins 1, 1, 2, 3, 5,
 * 8, 13, and so on. This is not just a mathematical curiosity. The sequence also regularly appears
 * in biological settings, for instance. It relates to the way shells grow in a spiral, and the number
 * of petals on many flowers is a number from this sequence. Create an array<> container with
 * 93 elements. Store the first 93 numbers in the Fibonacci series in the array and then output
 * them one per line. Any idea why we’d be asking you to generate 93 Fibonacci numbers and
 * not, say, 100?
 */

#include <iostream>
#include <array>

static_assert(sizeof(unsigned long long) >= 8,
"This program expects to have a unsigned long long type at least of 64-bit.");

int
main(void)
{
        const size_t size {93};
        std::array<unsigned long long, size> fib {1, 1};

        std::cout << fib[0] << '\n' << fib[1] << std::endl;
        for (size_t i {2}; i < size; ++i) {
                fib[i] = fib[i - 1] + fib[i - 2];
                std::cout << fib[i] << std::endl;
        }
}
