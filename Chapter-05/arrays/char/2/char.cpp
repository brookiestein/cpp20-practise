#include <iostream>

int
main(void)
{
        char vowels[6] {'a', 'e', 'i', 'o', 'u', '\0'};

        for (size_t i {}; vowels[i]; i++) {
                std::cout << vowels[i] << " ";
        }

        std::cout << std::endl;
}
