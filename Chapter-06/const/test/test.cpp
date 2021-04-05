/* Testing for whether a non-const value can be stored in a const pointer. */
#include <iostream>

int
main(void)
{
        unsigned int age {19};
        const unsigned int * const page { &age };
        std::cout << "I'm " << *page << " years old." << std::endl;
}
