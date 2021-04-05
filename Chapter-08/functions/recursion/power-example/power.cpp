/* Version of power (made at the beginning of the chapter) using recursion. */
#include <iostream>

double power(double x, int n);

int
main(void)
{
        for (int i {-3}; i <= 3; ++i)
                std::cout << power(8.0, static_cast<double>(i))
                        << '\t';
        std::cout << std::endl;
}

double
power(double x, int n)
{
        if (n == 0.0) return 1.0;
        else if (n > 0.0) return x * power(x, n - 1);
        else /* n < 0 */ return 1.0 / power(x, -n);
}
