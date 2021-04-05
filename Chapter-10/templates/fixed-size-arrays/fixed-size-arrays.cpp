/* Making a template with fixed-size arrays as template arguments. */

#include <iostream>
#include <span>

template <typename T> T average(std::span<const T> data);

int
main()
{
        double doubles[2] { 1.0, 2.0 };
        double moreDoubles[] { 1.0, 2.0, 3.0, 4.0, 5.0 };
        int ints[] { 1, 2, 3, 4 };

        std::cout << average<double>(doubles) << std::endl;
        std::cout << average<double>(moreDoubles) << std::endl;
        std::cout << average<int>(ints) << std::endl;
}

template <typename T>
T average(std::span<const T> data)
{
        T sum {};
        for (size_t i {}; i < data.size(); ++i)
                sum += data[i];
        return sum / data.size();
}
