#include <iostream>

template <typename ReturnType, typename T1, typename T2> ReturnType larger(const T1& a, const T2& b);

int
main()
{
        std::cout << "Larger of 1.5 and 2 is: " << larger<int>(1.5, 2.5) << std::endl;
        std::cout << "Larger of 1.5 and 2 is: " << larger<int, double>(3, 2.5) << std::endl;
        std::cout << "Larger of 1.5 and 2 is: " << larger<int, double, int>(3.14, 4.15) << std::endl;
}

template <typename ReturnType, typename T1, typename T2>
ReturnType larger(const T1& a, const T2& b)
{
        return static_cast<ReturnType>(a > b ? a : b);
}
