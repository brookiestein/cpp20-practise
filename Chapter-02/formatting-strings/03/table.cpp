#include <iostream>

int
main()
{
        int a {10};
        double b {3.14};
        char c {'B'};
        std::string d = "Brayan";
        std::cout << "|" << a << "|\t|" << b << "|\n"
                << "|" << c << "|\t|" << d << "|"
                << std::endl;
        return 0;
}
