/* Input vs Output parameters:
 * Testing in other way the Ex7_06 exercise. */

#include <iostream>
#include <string>
#include <vector>

void list_words(const std::vector<std::string>& words);
void find_words(std::vector<std::string>& words,
                const std::string& text,
                const std::string& separators);

int
main()
{
        std::string text {};
        std::cout << "Enter a text ending with *:\n";
        std::getline(std::cin, text, '*');

        std::vector<std::string> words {};
        const std::string separators {" .;:.\"!?'\n"};

        find_words(words, text, separators);
        list_words(words);
}

void
find_words(std::vector<std::string>& words,
        const std::string& text,
        const std::string& separators)
{
        size_t start {text.find_first_not_of(separators)};

        while (start != std::string::npos) {
                size_t end {text.find_first_of(separators, start + 1)};
                if (end == std::string::npos) { /* If a separators was not found. */
                        end = text.length();
                }

                words.push_back(text.substr(start, end - start));
                start = text.find_first_not_of(separators, end + 1);
        }
}

void
list_words(const std::vector<std::string>& words)
{
        size_t count {};
        for (const auto& word : words) {
                std::cout << word << '\t';
                if (++count % 5 == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
}
