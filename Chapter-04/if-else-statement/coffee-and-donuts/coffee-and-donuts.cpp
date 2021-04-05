#include <iostream>
#include <cctype>

int
main(void)
{
        char coffee {}, donuts {};

        std::cout << "Do you have coffee? [y/n]: ";
        std::cin >> coffee;
        std::cout << "Do you have donuts? [y/n]: ";
        std::cin >> donuts;

        coffee  = tolower(coffee);
        donuts  = tolower(donuts);

        if (coffee == 'y') {
                if (donuts == 'y') {
                        std::cout << "You have both coffee as donuts.";
                } else {
                        std::cout << "You have coffee, but not donuts.";
                }
        } else {
                std::cout << "You don't have coffee.";
        }

        std::cout << std::endl;
}
