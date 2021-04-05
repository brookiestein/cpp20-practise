/* Writing an algorithm to calculate n! with recursion. */
#include <iostream>

unsigned long long factorial(unsigned int n);

int
main(void)
{
        unsigned long long n {5};
        std::cout << n << "'s factorial is: " << factorial(n) << std::endl;
}

unsigned long long
factorial(unsigned int n)
{
        if (n <= 1) return 1LL;
        return n * factorial(n - 1);
}
