#include <iostream>

/* So, const here would be pointless... */
long larger(long a, long b);

int
main(void)
{
        int a {42}, b {74};
        std::cout << "The larger value is "
                << larger(static_cast<long>(a), static_cast<long>(b))
                << std::endl;
}

/* const here makes more sense. The values passed by-value (not by-reference)
 * won't be modified by the function. */
long
larger(const long a, const long b)
{
        return a > b ? a : b;
}
