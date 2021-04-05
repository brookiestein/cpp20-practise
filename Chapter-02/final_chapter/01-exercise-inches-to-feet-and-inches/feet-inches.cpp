#include <iostream>

int
main(void)
{
        const short one_foot_inches {12};
        int feet {}, inches {}, input {};

        std::cout << "Enter the inches to be calculated: ";
        std::cin >> input;

        feet    = input / one_foot_inches;
        inches  = input % one_foot_inches;

        std::cout << input << " inches are " << feet << " feet and "
                << inches << " inches." << std::endl;
        return 0;
}
