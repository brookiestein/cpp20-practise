/* Sort a vector of strings both lexicographically and by length. */

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <typename T> void printVector(const std::vector<T>& values,
                std::string_view message = "Values:", size_t perline = 5);

int
main()
{
        std::vector<std::string> names {
                "Frodo Baggins", "Gandalf the Gray",
                "Aragon", "Samwise Gamgee", "Peregrin Took",
                "Mariadoc Brandybuck", "Gimli",
                "Legolas Greenleaf", "Boromir"
        };

        printVector(names);

        /* Let's sort the vector lexicographically: */
        std::sort(names.begin(), names.end());
        printVector(names, "Lexicographically sorted values:");

        /* Let's sort the vector by length: */
        std::sort(names.begin(), names.end(), [] (auto& left, auto& right) {
                return left.length() < right.length();
        });
        printVector(names, "Values sorted by length:");
}

template <typename T> void
printVector(const std::vector<T>& values, std::string_view message, size_t perline)
{
        std::cout << message << std::endl;
        size_t count {};
        for (size_t i {}; i < values.size(); ++i) {
                if (!(count++ % perline))
                        std::cout << std::endl;
                std::cout << values[i] << (i < values.size() - 1 ? ", " : "\n");
        }
        std::cout << std::endl;
}
