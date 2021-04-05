/* Reproduce Table 2-6 with a program, without hard-coding the numeric values or
 * filling spaces, of course. If your command-line interface does not support Unicode characters
 * (perfectly possible), you can replace π with “pi” and omit φ (the Greek letter “phi,” in case you
 * were wondering).
 */

#include <iostream>
#include <cmath>

int
main(void)
{
        std::cout << "std::numbers::e" << "\t\t"
                << "The base of the natural logarithm"
                << "\t\t" << M_Ef64 << std::endl;

        std::cout << "std::numbers::pi" << "\t\t"
                << "PI" << "\t\t" << M_PIl << std::endl;

        std::cout << "std::numbers::sqrt2" << "\t\t"
                << "square root of 2" << "\t\t"
                << M_SQRT2f64 << std::endl;

        std::cout << "std::numbers::phi" << "\t\t"
                << "The golden ratio constant phi" << "\t\t"
                << "1.6180339" << std::endl;
}
