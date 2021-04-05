#include <iostream>
#include <compare>

int
main(void)
{
        int a {}, b {};

        std::cout << "Enter a number: ";
        std::cin >> a;
        std::cout << "Enter another number: ";
        std::cin >> b;

        std::strong_ordering ordering {a <=> b};
        std::cout << std::boolalpha;

        std::cout << "Is " << a << " less than " << b << " ? "
                << ordering::less << std::endl;

        std::cout << "Is " << a << " greater than " << b << " ? "
                << ordering::greater << std::endl;

        std::cout << "Is " << a << " equals to " << b << " ? "
                << ordering::equal << std::endl;
}
