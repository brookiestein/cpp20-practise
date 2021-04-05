/* Exercise 9-1: Adapt the Ex9_01 program to use string_view. */

#include <iostream>
#include <optional>
#include <string>
#include <string_view>

std::optional<size_t> find_last(std::string_view text, char to_find,
                std::optional<size_t> start_index = std::nullopt);

int
main()
{
        std::string phrase { "Growing old is mandatory. Growing up is optional." };
        std::string_view view { phrase };
        std::optional<size_t> found_a { find_last(view, 'a') };
        std::optional<size_t> found_b { find_last(view, 'b') };
        std::optional<size_t> found_i { find_last(view, 'i', 10) };

        if (found_a)
                std::cout << "The 'a' character was found at " << *found_a
                        << " as its last occurrence." << std::endl;

        if (found_b.has_value())
                std::cout << "The 'b' character was found at " << found_b.value()
                        << " as its last occurrence." << std::endl;

        if (found_i != std::nullopt)
                std::cout << "The 'i' character was found at " << *found_i
                        << " index." << std::endl;
}

std::optional<size_t> find_last(std::string_view text, char to_find,
                std::optional<size_t> start_index)
{
        if (text.empty())
                return std::nullopt;

        size_t index { start_index.value_or(text.size() - 1) };

        while (true) {
                if (text[index] == to_find)
                        return index;
                if (index == 0)
                        return std::nullopt;
                --index;
        }
}
