/* Here passes something interesting:
 * Depending on which variable is first declared,
 * larger will be the second one declared. Hmm...*/
#include <iostream>

template <typename T> const T& larger(const T& a, const T& b);

int
main()
{
        int small_int {10};
        int big_int   {17'011'983};

        std::cout << "Larger is " << *larger(&big_int, &small_int) << std::endl;
}

template <typename T> const T&
larger(const T& a, const T& b)
{
        return a > b ? a : b;
}
