/* Create a program that uses a do - while loop to count the number of
 * nonwhitespace characters entered on a line.
 * The count should end when the first # character is found.
 */

#include <iostream>
#include <cctype>

int
main(void)
{
        size_t count {};
        char input {};

        do {
                std::cout << "Enter a character: ";
                std::cin >> input;
                if (input != ' ' && input != '#')
                        ++count;
        } while (input != '#');

        std::cout << "You entered " << count << " nonwhitespace characters.\n";
}
