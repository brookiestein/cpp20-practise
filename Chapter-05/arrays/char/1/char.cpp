#include <iostream>
#include <cctype>

int
main(void)
{
        const size_t max_length {100};
        char text[max_length] {};

        std::cout << "Enter a text line: ";
        std::cin.getline(text, max_length, EOF);
        std::cout << "You've entered:\n" << text << std::endl;

        size_t vowels {};
        size_t consonants {};
        for (size_t i {}; text[i] != '\0'; ++i) {
                if (!std::isalpha(text[i])) /* We have nothing to do if it's so. */
                        continue;

                switch (std::tolower(text[i]))
                {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                        ++vowels;
                        break;
                default:
                        ++consonants;
                }
        }

        std::cout << "That text has " << vowels << " vowels and "
                << consonants << " consonants." << std::endl;
}
