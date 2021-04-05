#include <iostream>

int
main(void)
{
        char ch0 {};
        char ch1 {};

        std::cout << "Enter a character: ";
        std::cin >> ch0;
        std::cout << "Enter another character: ";
        std::cin >> ch1;

        std::cout << std::boolalpha;
        std::cout << "The expresion "
                << ch0 << " < " << ch1
                << " results in " << (ch0 < ch1) << std::endl;

        std::cout << "The expresion "
                << ch0 << " > " << ch1
                << " results in " << (ch0 > ch1) << std::endl;

        std::cout << std::noboolalpha;
        std::cout << "The expresion "
                << ch0 << " == " << ch1
                << " results in " << (ch0 == ch1) << std::endl;
}
