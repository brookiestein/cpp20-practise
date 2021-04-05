#include <iostream>
#include <string>

int
main(void)
{
        std::string text {}; /* The string to be modified. */
        std::cout << "Enter a string terminated by *:\n";
        std::getline(std::cin, text, '*');

        std::string word {}; /* The word to be replaced. */
        std::cout << "Enter the word to be replaced: ";
        std::cin >> word;

        std::string replacement {}; /* The word to be sustituted. */
        std::cout << "Enter the string to be sustituted for " << word << ": ";
        std::cin >> replacement;

        if (word == replacement) {
                std::cout << "Both the word to be replaced as the word to be sustituted\n"
                        << "are the same. So the operation will be aborted." << std::endl;
                return 1;
        }

        size_t start {text.find(word)};

        while (start != std::string::npos) {
                text.replace(start, word.length(), replacement);
                start = text.find(word, start + replacement.length());
        }

        std::cout << "The text you entered is now:\n"
                << text << std::endl;
}
