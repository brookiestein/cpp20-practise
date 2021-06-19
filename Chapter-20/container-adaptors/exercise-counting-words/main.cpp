#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

using Words = std::vector<std::string_view>;
using WordsCounts = std::map<std::string_view, size_t>;

Words extractWords(std::string_view text, std::string_view separators = " ,.!?\"\n");
WordsCounts countWords(const Words& words);
void showWordCounts(const WordsCounts& wordCounts);

int
main()
{
        std::string text {}; /* Text to extract words from. */
        std::cout << "Enter a text terminating by *: ";
        std::getline(std::cin, text, '*');

        Words words { extractWords(text) };
        if (words.empty()) {
                std::cout << "There are no words to work on.\n";
                return 0;
        }

        showWordCounts(countWords(words));
}

Words
extractWords(std::string_view text, std::string_view separators)
{
        Words words;
        size_t start { text.find_first_not_of(separators) };

        while (start != std::string::npos) {
                size_t end { text.find_first_of(separators, start + 1) };
                if (end == std::string::npos)
                        end = text.length();
                words.push_back(text.substr(start, end - start));
                start = text.find_first_not_of(separators, end + 1);
        }
        return words;
}

/* Interesting:
 * If there is a key *word* then increment its value,
 * if there's not, then 'make' one, zero-initialized (because of size_t),
 * return an lvalue reference to it, and finally increment it to 1! */
WordsCounts
countWords(const Words& words)
{
        WordsCounts result;
        for (auto& word : words)
                ++result[word];
        return result;
}

void
showWordCounts(const WordsCounts& wordCounts)
{
        const size_t words_per_line {5};
        size_t words_in_line {};
        char previous_initial {};
        for (const auto& [word, count] : wordCounts) {
                if (count < 2) continue;
                if ((previous_initial && word[0] != previous_initial) || words_in_line++ == words_per_line) {
                        words_in_line = 0;
                        std::cout << std::endl;
                }

                std::cout << word << " (" << count << ") ";
                previous_initial = word[0];
        }
        std::cout << std::endl;
}
