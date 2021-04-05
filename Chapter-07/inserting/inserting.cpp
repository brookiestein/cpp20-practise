/* Inserting a string into another. */
#include <iostream>
#include <string>

int
main(void)
{
        std::string phrase {"We can insert a string."};
        std::string word {"a string into "};

        /* + 1 to include the white space. */
        phrase.insert(phrase.rfind('a'), word, word.find('a'), word.rfind(' ') + 1);

        std::cout << phrase << std::endl;
}
