/* Exercise 9-5. As promised, write yet another variant of Ex8_09A , Ex8_09B , and Ex8_09C , */
/* where this time the average10() function uses one of the vocabulary types seen in this */
/* chapter. Show that this one function can be called both for fixed-size C-style arrays and */
/* std::array<> containers, and only so for arrays of ten elements. */
#include <iostream>
#include <span>

double average10(std::span<double, 10> numbers);

int
main()
{
        double numbers[] = {1.5, 3.14, 7.64, 2.3, 5.55, 4.34, 2.87, 9.09, 10.0, 12.512};
        double average   = average10(numbers);
        std::cout << "The average is " << average << std::endl;
}

double
average10(std::span<double, 10> numbers)
{
        double sum {};
        for (auto n : numbers)
                sum += n;
        return sum / 10;
}
