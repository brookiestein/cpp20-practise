#include <iostream>
#include <memory>

int
main()
{
        std::unique_ptr<unsigned> original { std::make_unique<unsigned>(42) };
        std::unique_ptr<unsigned> copy { std::move(original) };

        std::cout << "Copy's value: " << *copy << std::endl;

        if (original)
                std::cout << "Original's value: " << *original << std::endl;
        else
                std::cout << "Original has nothing." << std::endl;
}
