#include <iostream>

#include "pair.hpp"

int
main()
{
        /* Using CTAD (Class Template Argument Deduction) */
        /* Deduced type: int, double for both cases. */
        Pair pair1 {10, 3.14};
        Pair pair2 {8, 2.0};
        /* Pair pair2 {8, 2}; /1* Deduced type: int, int: Does not work. *1/ */

        std::cout << std::boolalpha;
        std::cout << "pair1 < pair2: " << (pair1 < pair2) << std::endl;
        std::cout << "pair1 <= pair2: " << (pair1 <= pair2) << std::endl;
        std::cout << "pair1 != pair2: " << (pair1 != pair2) << std::endl;
        std::cout << "pair1 == pair2: " << (pair1 == pair2) << std::endl;
        std::cout << "pair1 > pair2: " << (pair1 > pair2) << std::endl;
        std::cout << "pair1 >= pair2: " << (pair1 >= pair2) << std::endl;

        std::cout << "Pair 1 itself:\n" << pair1 << std::endl;
        std::cout << "Pair 2 itself:\n" << pair2 << std::endl;;
}
