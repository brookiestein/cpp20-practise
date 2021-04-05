#include <iostream>
#include <string>

int
main(void)
{
        std::string text {};
        std::string word {};
        std::cout << "Enter a text to search from, and press Enter: ";
        std::getline(std::cin, text);
        std::cout << "Enter a word to search in the given text, and press Enter: ";
        std::getline(std::cin, word);

        size_t count {}; /* Counts the occurrences of word, if any. */
        size_t index {}; /* Stores the index where word was found. */

        while ((index = text.find(word, index)) != std::string::npos) {
                ++count;
                index += word.length();
        }

        std::cout << "Your text contained " << count << " occurrences of \""
                << word << "\"." << std::endl;
}
