#include <iostream>
#include <span>

double
largest(std::span<double> numbers)
{
        double max { numbers[0] };
        for (auto n : numbers)
                if (max < n)
                        max = n;
        return max;
}

int
main()
{
        double numbers[] { 1.5, 3.14, 445.54, 75.76, 80.02 };
        double lgst { largest(numbers) };
        std::cout << "The largest number of the array is: " << lgst << std::endl;
}
