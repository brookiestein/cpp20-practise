#include <iostream>
#include <format>

int
main(void)
{
        int a {};
        int b {};

        std::cout << "Enter a number (a): ";
        std::cin >> a;
        std::cout << "Enter another number (b): ";
        std::cin >> b;

        std::string msg {
                std::format("a is {} b", a < b ? "less than" : (a == b ? "equals to" : "greater than"))
        };
}
