#include <iostream>
#include <numbers>

namespace math
{
        const auto sqrt2 { 1.414213562373095 }; /* 2's square */
        auto square(const auto& x) { return x * x; }
        auto pow4(const auto& x) { return square(square(x)); }
}

int
main(void)
{
        std::cout << "math::sqrt2 has the value: " << math::sqrt2 << std::endl;
        std::cout << "math::sqrt2 - std::numbers::sqrt2 = "
                << (math::sqrt2 - std::numbers::sqrt2) << std::endl;
        std::cout << "square of " << math::sqrt2 << " is "
                << math::square(math::sqrt2) << std::endl;
}
