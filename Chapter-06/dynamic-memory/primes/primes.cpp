#include <iostream>
#include <cmath>

int
main(void)
{
        int max {};
        std::cout << "How many primes would you like? ";
        std::cin >> max;

        if (max <= 0) return 0;

        unsigned int *primes {new unsigned int[max] {}};
        primes[0] = 2; /* First prime. */
        size_t trial {3}; /* Next candidate to be tested. */
        size_t count {1}; /* Number of primes found. */

        while (count < max) {
                bool is_prime {true};

                const auto limit {static_cast<unsigned>(std::sqrt(trial))};
                for (size_t i {}; i < limit && is_prime; ++i) {
                        is_prime = trial % primes[i] > 0;
                }

                if (is_prime)
                        primes[count++] = trial;

                trial += 2;
        }

        for (size_t i {}; i < max; ++i) {
                std::cout << primes[i] << "\t";
                if ((i + 1) % 10 == 0)
                        std::cout << std::endl;
        }
        std::cout << std::endl;

        delete[] primes;
        primes = nullptr;
}
