#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "foo.hpp"

template <typename T>
void show(const std::vector<T>& data, std::string_view success, std::string_view err);
std::string to_lower(std::string_view string);

int
main()
{
        std::vector<int> integers { 14, 56, 94, 43, 76, 82 };
        int number_to_search_for {};
        std::cout << "Enter a number: ";
        std::cin >> number_to_search_for;

        auto matching_ints { foo(integers, [number_to_search_for] <typename T> (T& value) {
                return value > number_to_search_for;
        })};

        show(matching_ints, "Numbers greater than the given number:",
                        "There are no numbers greater than the given number.");

        std::cout << std::endl;

        std::vector<char> chars;
        std::string text;
        std::cout << "Enter a word or text, end with an *: ";
        std::getline(std::cin, text, '*');
        /* Enter all characters into the vector for the foo template to work appropriately. */
        for (size_t i {}; i < text.length(); ++i) chars.push_back(text[i]);

        auto matching_chars { foo(chars, [] <typename T> (T& value) -> bool {
                return value >= 'A' && value <= 'Z';
        })};

        show(matching_chars,
                "Capital letters of the text:",
                "There are no capital letters in the text.");

        std::cout << std::endl;

        std::vector<std::string> strings {
                "Kayak", "Racecar", "Brayan",
                "Air plain", "Computer", "Noon"
        };

        /* I know this solution is a little bit weird because how I know that
         * value has the length() member? I do this because I do know, but
         * it is not that portable, though. */
        auto palindromes { foo(strings, [] <typename T> (T& value) -> bool {
                std::string word;
                for (size_t i {value.length() - 1}; i > 0; --i)
                        word += value[i];
                word += value[0];
                return to_lower(word) == to_lower(value);
        })};

        show(palindromes,
                "Palindromes words:",
                "There are no palindromes words.");
}

template <typename T>
void show(const std::vector<T>& data, std::string_view success, std::string_view err)
{
        if (data.empty()) {
                std::cout << err << std::endl;
                return;
        } else {
                std::cout << success << std::endl;
        }

        for (size_t i {}; i < data.size(); i++)
                std::cout << data[i] << ' ';
        std::cout << std::endl;
}

std::string
to_lower(std::string_view string)
{
        std::string new_str;
        for (size_t i {}; i < string.length(); ++i)
                new_str += std::tolower(string[i]);
        return new_str;
}
