#include <iostream>

template <typename T, auto lower, auto upper>
bool is_in_range(const T& value)
{
        return (value >= lower && value <= upper);
}

int
main()
{
        std::cout << is_in_range<int, 0, 50>(100) << std::endl;
}
