/* Passing multidimensional arrays to functions. */

#include <iostream>
#include <array>

double sum(const double multi[][4], size_t rows);

int
main(void)
{
        double beans[3][4] {
                {1.0, 2.0, 3.0, 4.0},
                {5.0, 6.0, 7.0, 8.0},
                {9.0, 10.0, 11.0, 12.0}
        };

        std::cout << "The sum is " << sum(beans, std::size(beans))
                << std::endl;
}

double
sum(const double multi[][4], size_t rows)
{
        double sum {};
        for (size_t i {}; i < rows; ++i) {
                for (auto num : multi[i]) {
                        sum += num;
                }
        }
        return sum;
}
