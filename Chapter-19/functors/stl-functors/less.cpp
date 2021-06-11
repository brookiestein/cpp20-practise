/* Meeting with the std::less<> functor. */

#include <iostream>
#include <functional>

int
main()
{
        std::less<> less;
        int a {};
        int b {};
        std::cout << "Enter a number: ";
        std::cin >> a;
        std::cout << "Enter another number: ";
        std::cin >> b;
        std::cout << (less(a, b) ? a : b) << " is less." << std::endl;
}
