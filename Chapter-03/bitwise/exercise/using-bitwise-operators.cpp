#include <iostream>

int
main(void)
{
        unsigned red {0xFF0000u};
        unsigned white {0xFFFFFFu};

        std::string RED         = "\e[1;31m";
        std::string WHITE       = "\e[1;37m";
        std::string NOCOLOR     = "\e[0m";

        std::cout << "Initial value: " << RED << "red" << NOCOLOR << "\t\t= " << std::hex << red << std::endl;
        std::cout << "Decimal value: " << "\t\t\t= " << std::dec << red << std::endl;
        std::cout << "Complement: " << RED << "~red" << NOCOLOR << "\t\t= " << NOCOLOR << std::hex << ~red << '\n' << std::endl;

        std::cout << "Initial value: " << WHITE << "white" << NOCOLOR << "\t\t= " << std::hex << white << std::endl;
        std::cout << "Decimal value: " << "\t\t\t= " << std::dec << white << std::endl;
        std::cout << "Complement: " << WHITE << "~white" << NOCOLOR << "\t\t= " << std::hex << ~white << '\n' << std::endl;

        std::cout << "Bitwise AND: " << RED << "red " << NOCOLOR
                << "& " << WHITE << "white" << NOCOLOR << "\t= "
                << (red & white) << std::endl;

        std::cout << "Bitwise OR: " << RED << "red " << NOCOLOR
                << "| " << WHITE << "white" << NOCOLOR << "\t\t= "
                << (red | white) << std::endl;
}
