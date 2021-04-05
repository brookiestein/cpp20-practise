/* Repeat the calculation in Exercise 6-3 but using a vector<> container allocated
 * in the free store. Test the program with more than 100,000 elements.
 * Do you notice anything interesting about the result?
 */

#include <iostream>
#include <vector>
#include <cmath>

int
main(void)
{
        int n {};
        std::cout << "How large would you like the array to be? ";
        std::cin >> n;

        if (n <= 0) {
                std::cout << "Nothing to do." << std::endl;
                return 0;
        }

        auto* numbers { new std::vector<double>(n) };
        double sum {};

        for (int i {}; i < n; ++i) {
                /* This notation is because numbers is a pointer-to-vector.
                 * So, I'm accessing to the vector by dereferencing it and then
                 * I'm accessing to the value at i index.
                 */
                (*numbers)[i] = 1.0 / ((i + 1) * (i + 1));
                sum += numbers->at(i);
        }

        delete numbers;
        numbers = nullptr;

        std::cout << "The result is " << std::sqrt(6.0 * sum) << std::endl;
}
