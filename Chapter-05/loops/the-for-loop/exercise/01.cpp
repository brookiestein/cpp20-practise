#include <iostream>

int
main(void)
{
        const unsigned int size {6};
        unsigned int height[size] {26, 37, 47, 55, 62, 75};

        unsigned int total {};
        for (size_t i {}; i < size; i++) {
                total += height[i];
        }

        const unsigned int average {total / size};
        std::cout << "The average is " << average << std::endl;

        unsigned int count {};
        for (size_t i {}; i < size; i++) {
                if (height[i] < average) count++;
                /* count += height[i] < average; /1* This is clever, but might need to be explained! *1/ */
        }

        std::cout << count << " people are below average height." << std::endl;
}
