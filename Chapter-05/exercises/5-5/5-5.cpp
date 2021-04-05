/* Exercise 5-4: Use std::cin.getline(...) to obtain a C-style string of maximum 1,000
 * characters from the user. Count the number of characters the user entered using an
 * appropriate loop. Next, write a second loop that prints out all characters, one by one, but in a
 * reverse order.
 *
 * Exercise 5-5. Write a program equivalent to that of Exercise 5-4, except for the following:
 * • If before you used a for loop to count the characters, you now use while , or vice versa.
 * • This time you should first reverse the characters in the array, before printing them
 * out left to right (for the sake of the exercise you could still use a loop to print out
 * the characters one by one).
 */

#include <iostream>

int
main(void)
{
        const size_t size {1'000};
        char input[size] {};

        std::cout << "Input a text: ";
        std::cin.getline(input, size);

        size_t count {};
        while (count < size && input[count] != '\0') {
                ++count;
        }

        /* Reversing the array */
        std::cout << "Reversing..." << std::endl;
        for (size_t f {}, l {count - 1}; f < count / 2; ++f, --l) {
                char aux {input[f]};
                input[f] = input[l];
                input[l] = aux;
        }
        std::cout << "Reversed." << std::endl;

        std::cout << "Printing..." << std::endl;
        size_t i {};
        while (i < count) {
                std::cout << input[i++];
        }
        std::cout << std::endl;
}
