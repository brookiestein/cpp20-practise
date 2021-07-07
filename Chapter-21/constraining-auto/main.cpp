#include <concepts>
#include <iostream>

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

int
main()
{
        Numeric auto x = 42;
        Numeric auto y = 3.14;
        Numeric auto z = "Lord Brookie";

        std::cout << x << ' ' << y << std::endl;
}
