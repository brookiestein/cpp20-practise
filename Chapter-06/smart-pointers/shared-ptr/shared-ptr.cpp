#include <iostream>
#include <memory>

int
main(void)
{
        auto age { std::make_shared<unsigned int> (19) };
        std::cout << "I'm " << *age << " years old." << std::endl;
}
