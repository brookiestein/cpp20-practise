#include <iostream>
/* #include <array> */

int
main(void)
{
        /* std::array these {1.0, 2.0, 3.0, 4.0}; */
        /* std::array those {1.0, 2.0, 3.0, 4.0}; */
        /* std::array them {1.0, 1.0, 5.0, 5.0}; */

        double these[] {1.0, 2.0, 3.0, 4.0};
        double those[] {1.0, 2.0, 3.0, 4.0};
        double them[]  {1.0, 1.0, 5.0, 5.0};

        if (these == those) std::cout << "these and those are equal." << std::endl;
        if (those != them) std::cout << "those and them are not equal." << std::endl;
        if (those > them) std::cout << "those are greater than them." << std::endl;
        if (them < those) std::cout << "them are less than those." << std::endl;
}
