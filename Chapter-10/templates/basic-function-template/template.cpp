#include <iostream>

template <typename T> const T& larger(const T& a, const T& b);

int
main()
{
        double d1 {1.5}, d2 {2.5};
        int big_int {17'011'983}, small_int {10};
        char a {'A'}, z {'Z'};

        std::cout << "Larger of " << d1 << " and " << d2 << " is "
                << larger(d1, d2) << std::endl;

        std::cout << "Larger of " << big_int << " and " << small_int << " is "
                << larger(big_int, small_int) << std::endl;

        std::cout << "Larger of " << a << " and " << z << " is "
                << larger(a, z) << std::endl;
}

template <typename T> const T&
larger(const T& a, const T& b)
{
        return a > b ? a : b;
}
