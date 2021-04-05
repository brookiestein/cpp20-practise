#include <iostream>
#include <cstring>

int
main(void)
{
        const char *name {"Brayan"};
        const char first_item {*name};

        /* Printing out item by item. */
        for (; *name != '\0'; name++) {
                std::cout << *name;
        }
        std::cout << std::endl;

        /* Printing out the whole string literal contained in name */
        for (; *name != first_item; name--);
        std::cout << name << std::endl;
}
