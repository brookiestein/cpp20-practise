/* Searching a string for characters from a set. */
#include <iostream>
#include <string>
#include <vector>

int
main(void)
{
        std::string text {}; /* The string to be searched. */
        std::cout << "Enter some text terminated by *:\n";
        std::getline(std::cin, text, '*');

        std::vector<std::string> words; /* Words found. */
        const std::string separators {" ,;:.\"!?'\n"}; /* Word delimiters. */
        size_t start { text.find_first_not_of(separators) };

        while (start != std::string::npos) {
                size_t end { text.find_first_of(separators, start + 1) }; /* Find end of word. */
                if (end == std::string::npos) {                                 /* Found a separator? */
                        end = text.length();                                    /* No, so set to end of text. */
                }
                words.push_back(text.substr(start, end - start)); /* Store the word. */
                start = text.find_first_not_of(separators, end + 1); /* Find first character of next word. */
        }

        std::cout << "Your string contains the following " << words.size() << " word:\n";
        size_t count {};

        for (const auto& word : words) {
                std::cout << word << "\t\t";
                if (++count % 5 == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
}
