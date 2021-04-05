/* This is a version of the program made in the chapter 5: Ex5_10 */
#include <iostream>
#include <string>
#include <cctype>

int
main(void)
{
        std::string text {};
        std::cout << "Enter a text: ";
        std::getline(std::cin, text);

        unsigned vowels {};
        unsigned consonants {};
        size_t count {};

        for (size_t i {}; i < text.length(); ++i) {
                if (!std::isalpha(text[i]))
                        continue;

                ++count;

                switch (std::tolower(text[i]))
                {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                        ++vowels;
                        break;
                default:
                        ++consonants;
                }
        }

        std::cout << "Your text has " << vowels << " vowels and "
                << consonants << " consonants." << std::endl;

        /* Why I'm using a variable to store the "length" of the string?
         * Because I want the whitespaces not to appear in the account.
         * Using the length() function they do appear.
         * But anyway, length() function is cool, too :D */
        std::cout << "Thus, making a string of "
                << count << " characters." << std::endl;
}
