#include <iostream>

int
main(void)
{
        unsigned age {19};
        double balance {1'000'000};

        /* if ((age < 20) ^ (balance >= 1'000'000)) { */
        /*         std::cout << std::boolalpha << true << std::endl; */
        /* } */

        if ((age < 20 || balance >= 1'000'000) && !(age < 20 && balance >= 1'000'000)) {
                std::cout << "True" << std::endl;
        } else {
                std::cout << "False" << std::endl;
        }
}
