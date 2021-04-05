#include <iostream>
#include <cctype>

int
main(void)
{
        char letter {};
        std::cout << "Enter a letter: ";
        std::cin >> letter;

        switch (std::tolower(letter))
        {
        case 'a': /* FALLTHROUGH */
        case 'e':
        case 'i':
        case 'o':
        case 'u': std::cout << "You've entered a vowel." << std::endl;
                  return 0;
        }

        std::cout << "You "
                << (std::isalpha(letter) ? "'ve entered a consonant" : "didn't enter a letter")
                << std::endl;
}
