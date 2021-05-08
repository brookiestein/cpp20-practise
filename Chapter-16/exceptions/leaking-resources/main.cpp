/* Exceptions sometimes may occasionate that resources be leaked. */

#include <iostream>
#include <array>
#include <cmath>

#include "Troubles.h"

double computeValue(int value);
double* computeValues(size_t howMany);
void printValues(const double* values, const size_t size);

int
main()
{
        try {
                const size_t numbers { 10'000 };
                double* values { computeValues(numbers) };
                printValues(values, numbers);
                delete[] values;
        } catch (const Trouble& ex) {
                std::cout << "Not worries. I've caught it!" << std::endl;
        }
}

double
computeValue(int value)
{
        if (value < 100)
                return std::sqrt(value);
        else
                throw Trouble { "The trouble with trouble is, it starts out as fun!" };
}

double*
computeValues(size_t howMany)
{
        /* Doing this so, will make values to be leaked. */
        /* double* values = new double[howMany]; */
        /* for (size_t i {}; i < howMany; ++i) */
        /*         values[i] = computeValue(i); */
        /* return values; */

        double* values { new double[howMany] };

        try {
                for (size_t i {}; i < howMany; ++i)
                        values[i] = computeValue(i);
        } catch (const Trouble& ex) {
                std::cout << "I sense trouble... Freeing memory..." << std::endl;
                delete[] values;
                throw;
        }

        return values;
}

void
printValues(const double* values, const size_t size)
{
        size_t count {};
        const size_t numbers_per_line {10};

        for (size_t i {}; i < size; ++i) {
                std::cout << values[i] << ' ';
                if (!(++count) % numbers_per_line) std::cout << std::endl;
        }
}
