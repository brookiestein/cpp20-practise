#include <iostream>

int
main(void)
{
        double income {100'000.00};
        double capital {1'000'000.00};

        if (income >= 100'000.00 || capital >= 1'000'000) {
                std::cout << "So, why do you want a borrow? " << std::endl;
        } else {
                std::cout << "You don't apply for a borrow." << std::endl;
        }
}
