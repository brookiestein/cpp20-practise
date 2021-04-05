#include <iostream>

int
main(void)
{
        unsigned a {}, b {};
        std::cout << "Enter a positive integer: ";
        std::cin >> a;
        std::cout << "Enter another positive integer: ";
        std::cin >> b;

        const unsigned larger {(a * (a / b) + b * (a / b + b / a))};
        const unsigned smaller {(b * (a / b) + a * (b / a) / (a / b + b / a))};

        std::cout << "The larger integer is " << larger << ".\n";
        std::cout << "The smaller integer is " << smaller << ".\n";
}
