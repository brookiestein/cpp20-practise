/* Testing whether a returned value from a function from cctype
 * works well with type bool of C++
 */

#include <iostream>
#include <cctype>

int
main(void)
{
        char value {};
        std::cout << "Enter a character: ";
        std::cin >> value;

        bool is_letter {static_cast<bool>(std::isalpha(value))};
        std::cout << std::boolalpha << "The entered value is a letter: " << is_letter << std::endl;
}
