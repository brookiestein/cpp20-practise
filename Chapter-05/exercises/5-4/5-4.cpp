/* Use std::cin.getline(...) to obtain a C-style string of maximum 1,000
 * characters from the user. Count the number of characters the user entered
 * using an appropriate loop. Next, write a second loop that prints out all
 * characters, one by one, but in a reverse order.
 */

#include <iostream>
#include <cctype>

int
main(void)
{
        const size_t size {1'000};
        char input[size] {};

        std::cout << "Input a text: ";
        std::cin.getline(input, size);

        size_t count {};
        for (; count < size && input[count] != '\0'; ++count);

        for (; static_cast<int>(count) >= 0; --count) {
                std::cout << input[count - 1];
        }
        std::cout << std::endl;
}
