#include <iostream>
#include <vector>

int
main(void)
{
        std::vector<unsigned> ages {16, 19, 25};
        auto ptr = &ages;

        std::cout << "She is " << (*ptr).at(0) << " years old." << std::endl;

        std::cout << "I'm " << ptr->at(1) << " years old." << std::endl;

        ptr->push_back(42);
        std::cout << "She's " << ptr->back() << " years old." << std::endl;
}
