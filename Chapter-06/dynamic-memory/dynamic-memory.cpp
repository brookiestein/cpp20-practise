#include <iostream>

int
main(void)
{
        unsigned int *age {new unsigned int {19}};
        std::cout << "I'm " << *age << " years old." << std::endl;
        delete age;
        age = nullptr;
}
