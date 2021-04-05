#include <iostream>
#include <string>

int
main(void)
{
        std::string text {};
        std::cout << "Enter some text, and press Enter: ";
        std::getline(std::cin, text);

        char letter {};
        std::cout << "Enter a letter to search from in the text: ";
        std::cin >> letter;

        std::cout << "The last occurrence of " << letter << " is at "
                << text.rfind(letter) << " index." << std::endl;
}
