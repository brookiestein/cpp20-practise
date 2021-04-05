#include <iostream>
#include <array>

int
main(void)
{
        size_t choice {};
        const size_t max_length {80};
        char stars[][max_length] {
                "Keanu Reaves",
                "Vin Diesel",
                "Michelle Rodriguez",
                "Jordana Brewster",
                "Paul Walker"
        };

        std::cout << "Choose a lucky star between 1 to " << std::size(stars) << ": ";
        std::cin >> choice;

        if (choice >= 1 && choice <= std::size(stars)) {
                std::cout << "Your lucky star is " << stars[choice - 1];
        } else {
                std::cout << "Sorry, you didn't get a lucky star.";
        }

        std::cout << std::endl;
}
