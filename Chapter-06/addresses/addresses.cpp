#include <iostream>

int
main(void)
{
        double number {};
        double *n {&number};

        std::cout << "Enter any number: ";
        std::cin >> *n;
        std::cout << "You wrote " << number << std::endl;

        double number2 {10};
        double *n2 {&number2};

        std::cout << "That multiplied by " << *n2 << " is "
                << *n2 * *n << std::endl;
}
