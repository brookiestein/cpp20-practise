#include <ios>
#include <iostream>
#include <cctype>

int
main(void)
{
        char ch {};

        std::cout << "Character\tHexadecimal\tDecimal\n";
        do {
                if (!std::isprint(ch))
                        continue;

                printf("%c \t\t %02x \t\t %i \n", ch, ch, ch);
        } while (ch++ < 127);
}
