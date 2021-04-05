/* Write a program that outputs the squares
 * of the odd integers from 1 up to a limit
 * that is entered by the user.
 */

#include <iostream>
#include <vector>
#include <cmath>

static void print(std::vector<double> values);

int
main(void)
{
        std::vector<double> numbers;
        /* Let's get the numbers. */
        for (;;) {
                double input {}; /* Temporary stores the value to be stored in numbers. */
                std::cout << "Enter a non-zero value or zero to end: ";
                std::cin >> input;
                if (input == 0)
                        break;
                numbers.push_back(input);
        }

        /* This is not necessary at all, but I think it serves to practise. */
        std::vector<double> squares;
        std::vector<double> odds;
        for (double n : numbers) {
                if (static_cast<int>(n) % 2 != 0) {
                        squares.push_back(std::sqrt(n));
                        odds.push_back(n);
                }
        }

        if (squares.empty()) {
                std::cout << "It hadn't any odd number." << std::endl;
                return 0;
        }

        /* It's the same than comparing with odds. */
        if (squares.size() > 1) {
                std::cout << "These odds numbers were found." << std::endl;
                print(odds);
                std::cout << "\nHere are the squares of these numbers:" << std::endl;
                print(squares);
        } else {
                std::cout << "This was the odd number that could be found." << std::endl;
                print(odds);
                std::cout << "\nHere is the square of that number:" << std::endl;
                print(squares);
        }
}

static void
print(std::vector<double> values)
{
        for (double v : values) {
                if (v == 0)
                        continue;
                std::cout << v << " ";
        }
        std::cout << std::endl;
}
