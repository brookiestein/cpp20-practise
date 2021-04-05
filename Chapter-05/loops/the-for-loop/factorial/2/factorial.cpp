#include <iostream>

int
main(void)
{
        unsigned int limit {};
        std::cout << "This program calculates n! up to limit, and sums\n"
                << "every integer from 1 to limit." << std::endl;
        std::cout << "What upper limit for n would you like? ";
        std::cin >> limit;

        std::cout << "Integer\t\t" << "Sum\t\t" << "Factorial" << std::endl;
        for (unsigned long long i {1}, sum {1}, fact {1}; i <= limit; i++, sum += i, fact *= i) {
                std::cout << i << "\t\t" << sum << "\t\t" << fact << std::endl;
        }
}
