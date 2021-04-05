/* Static variables exist as far as the program is executing. */
/* Static variables not initializated, are initializated with zero */
#include <iostream>

unsigned int
nextInteger(void)
{
        static unsigned int count;
        return ++count;
}

int
main(void)
{
        std::cout << nextInteger() << std::endl;
        std::cout << nextInteger() << std::endl;
        std::cout << nextInteger() << std::endl;
        std::cout << nextInteger() << std::endl;
        std::cout << nextInteger() << std::endl;
}
