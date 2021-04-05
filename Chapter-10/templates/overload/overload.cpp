#include <iostream>

template <typename T> const T& larger(const T& a, const T& b);
template <typename T> const T* larger(const T* a, const T* b);

int
main()
{
        int big_int {17'011'983};
        int small_int {10};

        larger(big_int, small_int);
        larger(&big_int, &small_int);
}

template <typename T> const T&
larger(const T& a, const T& b)
{
        std::cout << "Called the reference-to-const template." << std::endl;
        return a > b ? a : b;
}

template <typename T> const T*
larger(const T* a, const T* b)
{
        std::cout << "Called the pointer-to-const T template." << std::endl;
        return *a > *b ? a : b;
}
