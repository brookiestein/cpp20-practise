/* Exercise 10-2. Alter the last lines of Ex10_01 ’s main() function as follows: */
/*   const auto a_string = "A", z_string = "Z"; */
/*   std::cout << "Larger of " << a_string << " and " << z_string */
/*             << " is " << larger(a_string, z_string) << std::endl; */
/* If you now run the program, you may very well get the following output (if not, try rearranging */
/* the order in which a_string and z_string are declared): */
/* Larger of 1.5 and 2.5 is 2.5 */
/* Larger of 3.5 and 4.5 is 4.5 */
/* Larger of 17011983 and 10 is 17011983 */
/* Larger of A and Z is A */
/* What’s that? "A" is larger than "Z" ? Can you explain */
/* Hint: To compare two character arrays, you could perhaps first convert them to another string */

#include <iostream>
#include <string>

template <typename T> T
larger(const T& a, const T& b);

int
main()
{
        /* Declaring a_string after z_string makes the larger template
         * to return me that its value, A, is larger than z_string's value, Z.
         */
        /* [...] I've not gotten to know why it has that behaviour. */
        auto z_string {"Z"};
        auto a_string {"A"};
        std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
        std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;
        std::cout << "Larger of 17011983 and 10 is " << larger(17011983, 10) << std::endl;
        std::cout << "Larger of " << a_string << " and " << z_string
                << " is " << larger(std::string { a_string }, std::string { z_string }) << std::endl;
}

template <typename T> T
larger(const T& a, const T& b)
{
        return a > b ? a : b;
}
