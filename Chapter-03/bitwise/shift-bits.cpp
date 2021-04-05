#include <iostream>

int
main(void)
{
        unsigned short number {16'387};
        std::cout << "Original value: " << number << std::endl;
        number <<= 2;
        std::cout << "Value after shifting 2 bits to the left: "
                << number << std::endl;
}
