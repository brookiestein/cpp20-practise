/* Exercise 8-3. Write a program that accepts from two to four command-line arguments. If it is
 * called with less than two or more than four arguments, output a message telling the user what
 * they should do and then exit. If the number of arguments is correct, output them, each on a
 * separate line. */

#include <iostream>
#include <string>
#include <vector>

std::string prompt_for_text(const std::string& message, char delimiter);
std::string reverse(const std::string& original);

int
main()
{
        std::string original { prompt_for_text("Enter a text ending with *:", '*') }; /* String to be reversed. */
        if (original.empty()) {
                std::cout << "There's nothing to do." << std::endl;
                return 0;
        }

        std::string reversed { reverse(original) }; /* Reversed string. */

        std::cout << "\nOriginal text:\n" << original << std::endl;
        std::cout << "\nReversed text:\n" << reversed << std::endl;
}

std::string
prompt_for_text(const std::string& message, char delimiter)
{
        std::cout << message << std::endl;
        std::string input {};
        std::getline(std::cin, input, delimiter);
        return input;
}

std::string
reverse(const std::string& original)
{
        const std::string delimiters {",.;:'\n"};
        std::string reversed {}; /* Reversed string. */
        std::vector<std::string> words {}; /* To break up the original string into
                                              words to store them easily in the reversed string */

        size_t start { original.find_first_not_of(delimiters) };
        while (start != std::string::npos) {
                size_t end { original.find_first_of(delimiters) };
                if (end == std::string::npos) {
                        end = original.size();
                }

                words.push_back(original.substr(start, end - start));
                start = original.find_first_not_of(delimiters, end + 1);
        }

        if (words.size() > 1) {
                /* Why long long? Because the size() function returns unsigned long, and it could generate
                * a problem with the loop's condition. long long will ensure that information won't be lost. */
                for (long long i { static_cast<long long>(words.size()) }; i >= 0; --i)
                        reversed += words[i];
        } else {
                for (long long i { static_cast<long long>(words[0].size()) }; i >= 0; --i)
                        reversed += words[0][i];
        }

        return reversed;
}
