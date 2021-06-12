/* A generic lambda is a lambda expression that have a placeholder
 * such like: auto, auto&, const auto& in its parameter list. */
/* In C++ 20, and further you can specify the type of a generic lambda,
 * such like you can do with a template. */
/* Why would you want to do that? Well, that technique disallow the
 * compiler to make implicit conversions such like:
 * auto greater { [] (const auto& a, const auto& b) { return a > b; } };
 * greater(5, 10.0);
 * Basically, you're passing an integer and a double to the lambda.
 * In that case, the compiler makes an implicit conversion in order to
 * make that operation possible.
 * Writing the lambda in the newer C++ 20's way, makes that impossible, unless
 * you cast one of the two values in order to have both equal. */

#include <iostream>
#include <string>

int
main()
{
        /* auto greater { [] (const auto& a, const auto& b) { return a > b; } }; */
        auto greater { [] <typename T> (const T& a, const T& b) { return a > b; } };
        std::cout << "Is 10 greater than 5? " << std::boolalpha
                << greater(10, 5) << std::endl;

        std::cout << "Enter a name: ";
        std::string name0 {};
        std::string name1 {};
        std::getline(std::cin, name0);
        std::cout << "Enter another name: ";
        std::getline(std::cin, name1);

        std::cout << "Is the first name, " << name0
                << ", greater than the second one, " << name1 << "? "
                << greater(name0, name1) << std::endl;
}
