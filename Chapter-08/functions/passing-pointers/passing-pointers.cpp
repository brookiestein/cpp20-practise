/* Passing pointers to functions. */

#include <iostream>
#include <array>

double average(const double items[], size_t size_of_items);

int
main()
{
        const double numbers[] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
        std::cout << "The average is " << average(numbers, std::size(numbers)) << std::endl;
}

double
average(const double items[], size_t size_of_items)
{
        double sum {};
        for (size_t i {}; i < size_of_items; ++i) {
                sum += items[i];
        }
        return sum / size_of_items;
}
