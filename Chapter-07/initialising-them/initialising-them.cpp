#include <iostream>
#include <string>

int
main(void)
{
        std::string complete_name { "Brayan Mejía Salazar" };
        std::string name { complete_name, 0, 6 };
        std::string surname { complete_name, 7 };
        std::cout << "My complete name is " << name << ' ' << surname << std::endl;
}
