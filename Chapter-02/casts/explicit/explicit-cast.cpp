#include <iostream>
#include <cmath>

int
main()
{
        double a {10.7}, b {15.8};
        int c {static_cast<int>(std::round(a + b))};
        std::cout << "The sum of " << a << " and " << b
                << " stored in an integer variable is "
                << c << std::endl;
        return 0;
}
