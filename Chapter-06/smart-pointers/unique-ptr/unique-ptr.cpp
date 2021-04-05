#include <iostream>
#include <memory>

int
main(void)
{
        std::unique_ptr<unsigned int> age { std::make_unique<unsigned int>(19) };
        std::cout << age.get() << std::endl;
        age.reset();
        std::cout << age.get() << std::endl;
}
