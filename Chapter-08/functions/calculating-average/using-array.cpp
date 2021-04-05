/* Calculatin the average of an array's items but using a fixed-lenght array.
 * In this case, instead of using a plain array, I'll use an array<>. */

#include <iostream>
#include <array>

double average(const std::array<double, 10>& values);

int
main(void)
{
        std::array<double, 10> values {
                1.0, 2.0, 3.0, 4.0, 5.0,
                6.0, 7.0, 8.0, 9.0, 10.0
        };

        std::cout << "The average is " << average(values) << std::endl;
}

double
average(const std::array<double, 10>& values)
{
        double sum {};
        for (auto value : values) {
                sum += value;
        }
        return sum / values.size();
}
