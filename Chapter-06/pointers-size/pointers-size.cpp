/* Getting the size of pointers. */

#include <iostream>

int
main(void)
{
        std::cout << sizeof(double) << " > " << sizeof(char16_t) << std::endl;
        std::cout << sizeof(double *) << " == " << sizeof(char16_t *) << std::endl;
}
