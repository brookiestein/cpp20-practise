#include <iostream>

template <typename T1, typename T2>
decltype(auto) larger(const T1& a, const T2& b)
{
        return a > b ? a : b;
}

int
main()
{
        std::cout << "Larger of 1.5 and 2 is: "
                << larger(1.5, 2)
                << std::endl;
}
