#include <iostream>

int
main(void)
{
        char letter {'A'};
        std::cout << "The letter is " << letter << " and its code is "
                << static_cast<unsigned int>(letter) << std::endl;

        ++letter;
        std::cout << "The letter now is " << letter << " and its code is "
                << static_cast<unsigned int>(letter) << std::endl;

        letter += 3;
        std::cout << "The letter now is " << letter << " and its code is "
                << static_cast<unsigned int>(letter) << std::endl;

        return 0;
}
