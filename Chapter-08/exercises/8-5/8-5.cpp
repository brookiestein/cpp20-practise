/* Exercise 8-5. Define a function that checks whether a given number is prime. Your primal check */
/* does not have to be efficient; any algorithm you can think of will do. In case you have forgotten, */
/* a prime number is a natural number strictly greater than 1 and with no positive divisors other */
/* than 1 and itself. Write another function that generates a vector<> with all natural numbers */
/* less or equal to a first number and starting from another. By default it should start from 1. */
/* Create a third function that given a vector<> of numbers outputs another vector<> containing */
/* all the prime numbers it found in its input. Use these three functions to create a program that */
/* prints out all prime numbers less or equal to a number chosen by the user (print, for instance, */
/* 15 primes per line). Note: In principle, you do not need any vector s to print these prime */
/* numbers; obviously, these extra functions have been added for the sake of the exercise. */

#include <iostream>
#include <vector>

bool is_it_prime(int number);
std::vector<int> generate_numbers(int limit, int start_from = 1);
std::vector<int> find_primes(std::vector<int>& numbers);
void print_primes(const std::vector<int>& primes, int limit);

int
main()
{
        std::vector<int> numbers { generate_numbers(1000, 50) };
        std::vector<int> primes { find_primes(numbers) };
        int limit {};
        std::cout << "What number would you like to be the upper limit? ";
        std::cin >> limit;
        if (limit < 1) limit = 1;
        print_primes(primes, limit);
}

bool
is_it_prime(int number)
{
        if (number <= 1)
                return false;

        size_t count {};
        for (int i = 1; i <= number; ++i)
                if (number % i == 0)
                        count++;

        return count == 2 ? true : false;
}

std::vector<int>
generate_numbers(int limit, int start_from)
{
        std::vector<int> numbers {};
        for (int i = start_from; i <= limit; ++i)
                numbers.push_back(i);
        return numbers;
}

std::vector<int>
find_primes(std::vector<int>& numbers)
{
        std::vector<int> primes {};
        for (auto n : numbers)
                if (is_it_prime(n))
                        primes.push_back(n);
        return primes;
}

void
print_primes(const std::vector<int>& primes, int limit)
{
        size_t count {};
        std::cout << "These are the primes numbers less than "
                << limit << " that were found:" << std::endl;
        for (auto p : primes) {
                if (p <= limit) {
                        std::cout << p << ' ';
                        if (++count == 15) {
                                std::cout << std::endl;
                                count = 0;
                        }
                }
        }
        std::cout << std::endl;
}
