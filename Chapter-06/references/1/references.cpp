#include <iostream>

static void print_through_reference(unsigned int& ref);

int
main(void)
{
        unsigned int age {19};
        unsigned int& rage { age };

        std::cout << "I'm " << rage << " years old." << std::endl;
        std::cout << "In my next birthday I'll turn to " << ++rage << std::endl;
        std::cout << "The original age variable has the value: ";
        print_through_reference(age);
        std::cout << "After calling the function which makes use of a reference\n"
                << "the age variable has the value: " << age << std::endl;
}

static void
print_through_reference(unsigned int& ref)
{
        std::cout << ref++ << std::endl;
        std::cout << "Later, I'll turn to " << ref << std::endl;
}
