#include <iostream>

int
main(void)
{
        unsigned ticket_number {127};

        switch (ticket_number)
        {
        case 127:
        case 387:
                std::cout << "You won the first place.";
                break;
        case 929:
                std::cout << "You won a special bonus.";
                /* [[fallthrough]]; */
        case 29:
        case 78:
                std::cout << "You won the second place.";
                break;
        }

        std::cout << '\n';
}
