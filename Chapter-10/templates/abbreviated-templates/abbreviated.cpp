/* You can abbreviate template functions such as:
 * template <typename T> T...
 * for:
 * auto fn(auto var)
 * Also, you can use pointers and references, such as
 * (const) auto* fn...
 * (const) auto& fn...
 */

#include <iostream>

const auto&
larger(const auto& a, const auto& b)
{
        return a > b ? a : b;
}

int
main()
{
        int a {5};
        int b {10};
        std::cout << "Larger of " << a << " and " << b
                << " is " << larger(a, b) << std::endl;
}
