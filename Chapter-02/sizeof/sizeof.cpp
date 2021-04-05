#include <iostream>

int
main()
{
        int height {74};
        std::cout << "The size of height is "
                << sizeof(height) << " bytes." << std::endl;
        std::cout << "The size of the 'long long' type is "
                << sizeof(long long) << " bytes." << std::endl;
        std::cout << "The size of the expression 'height * height / 2' is "
                << sizeof(height * height / 2) << " bytes." << std::endl;
        return 0;
}
