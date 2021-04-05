/* Implement a program that prompts for the input of a letter. Use a library function
 * to determine whether the letter is a vowel and whether it is lowercase or not, and output the
 * result. Finally, output the lowercase letter together with its character code as a binary value. As
 * a bonus exercise, you could try to do the latter without the use of std::format() ?
 */

#include <iostream>
#include <cctype>
#include <bitset>

int
main(void)
{
        char l {};
        std::cout << "Enter a letter: ";
        std::cin >> l;
        l = std::tolower(l);

        if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
                std::cout << "You entered a vowel." << std::endl;
        else
                std::cout << "You entered a consonant." << std::endl;

        std::cout << l << " " << std::bitset<32>(static_cast<int>(l)) << std::endl;
}
