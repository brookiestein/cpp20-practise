/* Exercise 9-6. Suppose you have a vector<> and you know for a fact that it contains */
/* exactly ten elements (or at least ten elements). Can you then call the average10() */
/* function of the previous example to compute the average of these ten elements (or the */
/* ten first elements)? Not directly, obviously, but it is possible! After all, all the necessary */
/* data (ten consecutive elements) is present in the vector. You may want to consult a */
/* Standard Library reference for this. */

#include <iostream>
#include <vector>
#include <span>
#include <optional>

#define LIMIT 10

std::optional<double> average10(std::span<double> numbers);

int
main()
{
        std::vector<double> numbers {
                1.5, 3.14, 7.64, 2.3, 5.55, 4.34, 2.87,
                9.09, 10.0, 12.512, 5.52, 14.50, 17.64 };
        std::optional<double> average { average10(numbers) };

        if (average)
                std::cout << "The average of the first ten numbers of the array is: "
                        << average.value() << std::endl;
        else
                std::cout << "The array does not have at least ten (10) elements."
                        << std::endl;
}

std::optional<double>
average10(std::span<double> numbers)
{
        if (numbers.empty())
                return std::nullopt;
        else if (numbers.size() < LIMIT)
                return std::nullopt;

        double sum {};
        for (size_t i {}; i < LIMIT; ++i)
                sum += numbers[i];
        return sum / LIMIT;
}
