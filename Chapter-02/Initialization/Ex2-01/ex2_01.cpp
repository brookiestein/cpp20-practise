#include <iostream>

int
main()
{
        int apple_count {15};
        int orange_count {5};
        int total_fruits {apple_count + orange_count};
        std::cout << "The value of apple_count is " << apple_count << std::endl;
        std::cout << "The value of orange_count is " << orange_count << std::endl;
        std::cout << "The value of total_fruits is " << total_fruits << std::endl;
        return 0;
}
