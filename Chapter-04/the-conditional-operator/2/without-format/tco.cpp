#include <iostream>

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
                a > b ? "a is greater than b" : (a == b ? "a is equals to b" : "a is less than b")
        };

        std::cout << msg << std::endl;

        /* std::cout */
        /* << (a > b ? "a is greater than b" : (a == b ? "a is equals to b" : "a is less than b")) */
        /* << std::endl; */
}
