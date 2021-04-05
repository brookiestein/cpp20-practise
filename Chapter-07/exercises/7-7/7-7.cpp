/* Create a program that reads an arbitrarily long sequence of integer numbers
 * typed by the user into a single string object. The numbers of this sequence are to be
 * separated by spaces and terminated by a # character. The user may or may not press Enter
 * between two consecutive numbers. Next, extract all numbers from the string one by one.
 */

#include <iostream>
#include <string>

int
main(void)
{
        std::cout << "Enter a list of numbers separated by spaces.\n"
                << "Put # when you've finished: ";
        std::string str {};
        std::getline(std::cin, str, '#');

        long sum {};
        size_t index {};
        while (true) {
                const size_t start {str.find_first_of("-0123456789", index)};
                if (start == std::string::npos) break;

                size_t end {str.find_first_not_of("-0123456789", start + 1)};
                if (end == std::string::npos) end = str.length();

                const size_t length {end - start};
                const auto substring {str.substr(start, length)};

                if (substring != "-") {
                        const int number {std::stoi(substring)};
                        sum += number;
                }

                index = end;
        }

        std::cout << "The sum of all the numbers you entered is " << sum << std::endl;
}
