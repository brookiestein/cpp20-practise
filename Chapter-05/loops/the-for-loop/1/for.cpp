#include <iostream>

int
main(void)
{
        unsigned int numbers[5] {10, 20, 67, 3, 101};
        unsigned int copy[5] {};

        for (size_t i {}; i < 5; i++) {
                copy[i] = numbers[i];
        }

        for (size_t i {}; i < 5; ++i) {
                std::cout << copy[i] << " ";
        }

        std::cout << '\n';
}
