#include <iostream>

int
main()
{
        long double number {5e3};
        std::cout << "The number's value is " << number << std::endl;
        std::cout << "The variable's size is " << sizeof(number) << std::endl;
        return 0;
}
