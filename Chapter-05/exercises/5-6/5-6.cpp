/* Create a vector<> container with elements containing the integers from 1
 * to an arbitrary upper bound entered by the user. Output the elements from
 * the vector that contain values that are not multiples of 7 or 13.
 * Output them ten on a line, aligned in columns.
 */

#include <iostream>
#include <vector>

int
main(void)
{
        std::vector<int> numbers;
        int limit {};

        std::cout << "How many numbers would you like me to work with? ";
        std::cin >> limit;

        if (limit <= 0) {
                std::cout << "Nothing to do." << std::endl;
                return limit;
        }

        for (int i {1}; i <= limit; ++i) {
                numbers.push_back(i);
        }

        size_t count {};
        const size_t per_line {10};
        for (auto value : numbers) {
                if (value % 7 == 0 || value % 13 == 0) continue;
                std::cout << value << "\t";
                if (++count == per_line) {
                        std::cout << std::endl;
                        count = 0;
                }
        }
        std::cout << std::endl;
}
