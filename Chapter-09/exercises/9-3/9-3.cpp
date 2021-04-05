/* Exercise 9-3. Adjust Ex8_13 to use vocabulary types. */
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <span>

std::optional<double> largest(std::span<const double> numbers);
std::optional<int> largest(std::span<const int> numbers);
std::optional<std::string> largest(std::span<const std::string> words);

int
main()
{
        std::vector<double> double_numbers { 1.54, 3.14, 7.74, 9.90, 5.875 };
        std::vector<int> integers { 10, 15, 512, 1'000, 1'512'000, 1 };
        /* std::vector<int> integers; /1* This will throw an exception in the second call to std::cout *1/ */
        std::vector<std::string> words {
                "Growing old is mandatory.",
                "Growing up is optional.",
                "You're the only one who can make your life better."
        };

        std::cout << "The largest double number is: "
                << *largest(double_numbers)
                << std::endl;
        std::cout << "The largest integer number is: "
                << largest(integers).value()
                << std::endl;
        std::cout << "The largest word is: "
                << largest(words).value_or("Empty!")
                << std::endl;
}

std::optional<double>
largest(std::span<const double> numbers)
{
        if (numbers.empty())
                return std::nullopt;
        double max { numbers[0] };
        for (auto cn : numbers)
                if (cn > max)
                        max = cn;
        return max;
}

std::optional<int>
largest(std::span<const int> numbers)
{
        if (numbers.empty())
                return std::nullopt;
        int max { numbers[0] };
        for (auto cn : numbers)
                if (cn > max)
                        max = cn;
        return max;
}

std::optional<std::string>
largest(std::span<const std::string> words)
{
        if (words.empty())
                return std::nullopt;
        std::string max_word { words[0] };
        for (const auto& word : words)
                if (word > max_word)
                        max_word = word;
        return max_word;
}
