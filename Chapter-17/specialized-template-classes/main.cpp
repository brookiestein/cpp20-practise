#include <iostream>
#include <string>

#include "stack.h"

int
main()
{
        std::string words[] { "The", "quick", "brown", "fox", "jumps." };
        Stack<std::string> wordStack;

        for (const auto& word : words)
                wordStack.push(word);

        auto newStack { wordStack };

        /* Display the words in reverse order. */
        while (!newStack.isEmpty())
                std::cout << newStack.pop() << ' ';
        std::cout << std::endl;

        /* Store the words in the original order from wordStack to newStack. */
        while (!wordStack.isEmpty())
                newStack.push(wordStack.pop());

        /* Display the words in the original order. */
        while (!newStack.isEmpty())
                std::cout << newStack.pop() << ' ';

        std::cout << "\nEnter a text line:" << std::endl;
        std::string text;
        std::getline(std::cin, text);

        Stack<const char> characters;
        for (size_t i {}; i < text.length(); ++i)
                characters.push(text[i]);

        /* Store the characters in reverse order in a new stack, by way of
         * that we can retrieve them in original sequence by poping them later. */
        Stack<const char> copyCharacters;
        while (!characters.isEmpty())
                copyCharacters.push(characters.pop());

        /* Display the text line in its original order. */
        while (!copyCharacters.isEmpty())
                std::cout << copyCharacters.pop() << ' ';
        std::cout << std::endl;
}
