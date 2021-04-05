/* Write a program that uses a while loop to accumulate the sum of an arbitrary
 * number of integers entered by the user. After every iteration, ask the user whether they are
 * done entering numbers. The program should output the total of all the values and the overall
 * average as a floating-point value.
 */

#include <iostream>
#include <vector>
#include <cctype>

int
main(void)
{
        std::vector<double> numbers;
        double total {};
        double average {};

        while (true) {
                double temp {};
                char reply {};
                std::cout << "Enter a number: ";
                std::cin >> temp;
                numbers.push_back(temp);
                total += temp;
                std::cout << "Are you done by entering numbers [y/n]? ";
                std::cin >> reply;
                if (std::tolower(reply) == 'y')
                        break;
        }

        average = total / numbers.size();

        std::cout << "You entered the following "
                << (numbers.size() > 1 ? "values" : "value")
                << std::endl;

        for (size_t i {}, count {}; i < numbers.size(); ++i) {
                std::cout << numbers.at(i) << " ";
                if (++count == 10) {
                        count = 0;
                        std::cout << std::endl;
                }
        }

        std::cout << "\nTotal: " << total << "\nAverage: " << average << std::endl;
}
