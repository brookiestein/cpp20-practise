/* A generic lambda is a lambda expression that have a placeholder
 * such like: auto, auto&, const auto& in its parameter list. */

#include <iostream>
#include <string>

int
main()
{
        auto greater { [] (const auto& a, const auto& b) { return a > b; } };
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
