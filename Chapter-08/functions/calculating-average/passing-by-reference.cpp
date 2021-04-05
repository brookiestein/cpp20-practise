/* Calculatin the average of an array but passing it by-reference. */

#include <iostream>
#include <array>

double average(const double (&values)[10]);

int
main(void)
{
        double values[] {
                1.0, 2.0, 3.0, 4.0, 5.0,
                6.0, 7.0, 8.0, 9.0, 10.0
        };

        std::cout << "The average is " << average(values) << std::endl;
}

double
average(const double (&values)[10])
{
        double sum {};
        for (auto value : values) {
                sum += value;
        }
        return sum / std::size(values);
}
