#include <iostream>

int
main(void)
{
        size_t count {};
        std::cout << "How many heights will you enter? ";
        std::cin >> count;
        if (count <= 0) {
                std::cout << "Nothing to do." << std::endl;
                return 0;
        }

        int heights[count];
        int entered {};
        int total {};
        int average {};

        while (entered < count) {
                std::cout << "Enter a height (in inches): ";
                std::cin >> heights[entered];
                if (heights[entered] > 0) {
                        total += heights[entered++];
                } else {
                        std::cout << "Height must be positive - try again.\n";
                }
        }

        average = total / count;
        std::cout << "The average height is " << average << std::endl;
}
