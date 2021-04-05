/* Exercise 8-9. Modify the solution of Exercise 8-8 such that it counts the number of times */
/* the call power(1.5,1000) performs a multiplication. Do so by replacing each multiplication */
/* with a helper function mult() that takes two arguments, prints a message of how many */
/* multiplications have been performed thus far, and then simply returns the product of both */

#include <iostream>

long double mult(long double n1, long double n2);
long double power(double x, int n);

int
main()
{
        const double base { 1.5 };
        const int exponent { 1000 };
        const long double result { power(base, exponent) };
        std::cout << "The result is: " << result << std::endl;
}

long double
mult(long double n1, long double n2)
{
        static size_t count {};
        std::cout << "Multiplication #" << ++count << std::endl;
        return n1 * n2;
}

long double
power(double x, int n)
{
        if (n == 0)
                return 1.0;
        else if (n < 0)
                return x / power(x, -n);
        else if (n % 2)
                return mult(x, power(x, n - 1));

        const auto y { power(x, n / 2) };
        return mult(y, y);
}
