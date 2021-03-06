/* Write a program that reads a text string of arbitrary length from the keyboard
 * and prompts for entry of a word that is to be found in the string. The program should find
 * and replace all occurrences of this word, regardless of case, by as many asterisks as
 * there are characters in the word. It should then output the new string. Only whole words
 * are to be replaced. For example, if the string is "Our house is at your disposal." and
 * the word that is to be found is "our" , then the resultant string should be as follows:
 * "*** house is at your disposal." and not "*** house is at y*** disposal." .
 */

#include <iostream>
#include <string>

int
main(void)
{
        std::string text {};
        std::cout << "Enter a text, and an asterisk when you've finished: ";
        std::getline(std::cin, text, '*');
        std::string word {};
        std::cout << "Enter a word to search from in the text: ";
        std::cin >> word;

        size_t start {text.find(word)};
        if (start == std::string::npos) {
                std::cout << word
                        << " couldn't be found, so the whole string will be equal."
                        << std::endl;
                std::cout << '\n' << text << std::endl;
                return 0;
        }

        text.replace(start, word.length(), word.length(), '*');
        std::cout << word << " was found, so the new string is as follows:\n";
        std::cout << '\n' << text << std::endl;
}
