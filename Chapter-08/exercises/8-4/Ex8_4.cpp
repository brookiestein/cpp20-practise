/* Exercise 8-4. Create a function, plus() , that adds two values and returns their sum. Provide
 * overloaded versions to work with int , double , and strings, and test that they work with the
 * following calls:
 * int n {plus(3, 4)};
 * double d {plus(3.2, 4.2)};
 * string s {plus("he", "llo")};
 * string s1 {"aaa"};
 * string s2 {"bbb"};
 * string s3 {plus(s1, s2)};
 * Can you explain why the following doesn’t work?
 * const auto d {plus(3, 4.2)}; */

#include <iostream>

const int plus(int a, int b);
const double plus(double a, double b);
const std::string plus(const std::string& a, const std::string& b);

int
main()
{
        std::cout << "int plus: " << plus(3, 4) << std::endl;
        std::cout << "double plus: " << plus(3.2, 4.2) << std::endl;
        std::cout << "std::string plus: " << plus("He", "llo") << std::endl;
        /* The following three lines would work even if s1 and s2 were both non-const
         * because the operation from non-const to const works, but not viceversa. */
        const std::string s1 { "aaa" };
        const std::string s2 { "bbb" };
        std::cout << plus(s1, s2) << std::endl;
        /* const auto d { plus(3, 4.2) }; */
}

const int
plus(int a, int b)
{
        return a + b;
}

const double
plus(double a, double b)
{
        return a + b;
}

const std::string
plus(const std::string& a, const std::string& b)
{
        return a + b;
}
