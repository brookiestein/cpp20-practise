#include <iostream>

int
main(void)
{
        unsigned int limit {};
        std::cout << "This program calculates n! and the sum of the integers "
                << "up to n for values 1 to limit.\n";
        std::cout << "What upper limit for n would you like? ";
        std::cin >> limit;

        /* This emulates the scope the for loop offers. So these variables after it
         * will leave from exist.
         */
        {
                unsigned int n {};
                unsigned int sum {};
                unsigned long long fact {1ULL};

                std::cout << "Integer\t\t" << "Sum\t\t" << "Factorial\n";
                while (++n <= limit) {
                        sum += n;
                        fact *= n;
                        std::cout << n << "\t\t" << sum << "\t\t" << fact << std::endl;
                }
        }
}
