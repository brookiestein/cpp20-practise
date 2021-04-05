#include <iostream>
#include <array>

int
main(void)
{
        std::array ages {16, 19, 25, 42, 49};
        std::cout << "The first element of the array is " << ages.front();
        std::cout << "\nThe last element of the array is " << ages.back();

        std::cout << "\nThis is the whole array." << std::endl;
        for (size_t i {}; i < ages.size(); ++i) {
                std::cout << ages.at(i) << " ";
        }
        std::cout << std::endl;
}
