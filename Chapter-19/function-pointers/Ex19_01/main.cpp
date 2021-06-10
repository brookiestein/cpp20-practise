/* First steps in function pointers. */

#include <iostream>

long sum(long a, long b) { return a + b; }
long product(long a, long b) { return a * b; }

int
main()
{
        /* long (*func_ptr)(long, long) { &product }; */
        /* It can also be defined as follows: */
        auto* func_ptr { &product };
        std::cout << "5 * 7 = " << func_ptr(5, 7) << std::endl;

        func_ptr = &sum;
        std::cout << "3 * (4 + 5) + 6 = "
                << func_ptr(product(3, func_ptr(4, 5)), 6)
                << std::endl;
}
