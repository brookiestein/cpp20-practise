/* Exercise 19-1. Define and test a lambda expression that returns the number of */
/* elements in a vector<string> container that begin with a given letter. */

#include <iostream>
#include <string>
#include <vector>

int usage(int rvalue);

int
main(int argc, char** argv)
{
        if (argc < 2)
                return usage(1);

        char letter = argv[1][0];

        std::vector<std::string> names {
                "Brayan", "Melvin", "Josué",
                "Camilo", "Byron", "José",
                "Mercedes", "María", "Carmen"
        };

        auto search_for { [=] () -> std::size_t {
                std::size_t count {};
                for (std::size_t i {}; i < names.size(); ++i)
                        if (names[i][0] == letter)
                                ++count;
                return count;
        }};

        auto items_matched { search_for() };
        std::cout << "The number of elements that start with " << letter
                << " is " << items_matched << std::endl;
}

int
usage(int rvalue)
{
        std::cout << "Usage: ./ex19-01 <a letter>" << std::endl;
        return rvalue;
}
