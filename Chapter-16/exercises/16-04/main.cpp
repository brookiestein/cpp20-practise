/* Exercise 16-4. Pick any number of Standard Library exception types from Figure 16-8 and */
/* write a program that causes each of them to be raised in turn (without actually throwing */
/* them yourself, of course). You should catch each of these exceptions and output the what() */
/* messages they contain, before moving on to triggering the next exception. */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string> /* To have access to std::string::npos */
#include <bitset> /* For throwing an invalid_argument exception. */

int
main()
{
        /* length_error exception: */
        try {
                auto numbers { std::vector<int>(std::string::npos) };
        } catch (const std::length_error& ex) {
                std::cout << "length_error exception caught: " << ex.what() << std::endl;
        }

        std::cout << std::endl;
        /* invalid_argument exception. */
        try {
                /* Btw, this example just was copied from cplusplus.com. */
                std::bitset<5> m_bitset { std::string("01234") };
        } catch (const std::invalid_argument& ex) {
                std::cout << "invalid_argument exception caught: " << ex.what() << std::endl;
        }
}
