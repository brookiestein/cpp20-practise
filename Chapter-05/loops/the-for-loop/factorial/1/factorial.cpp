#include <iostream>

int
main(void)
{
        std::cout << "This program calculates n! and the sum of the integers "
                << "up to n for values 1 to limit." << std::endl;
        std::cout << "What upper limit to n would you like? ";
        unsigned int limit {};
        std::cin >> limit;

        std::cout << "Integer\t\tSum\t\tFactorial\n";
        for (unsigned long long i {1}, sum {}, fact {1}; i <= limit; i++) {
                sum += i;
                fact *= i;
                std::cout << i << "\t\t" << sum << "\t\t" << fact << std::endl;
        }
}
