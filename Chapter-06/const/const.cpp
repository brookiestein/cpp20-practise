#include <iostream>

int
main(void)
{
        const float pi {3.1415F};
        const float pi2 {3.141516F};
        const float * const ppi {&pi};

        std::cout << *ppi << std::endl;
        /* Error: ppi is a const-pointer which points to a const float variable. */
        /* ppi = &pi2; */
        /* std::cout << *ppi << std::endl; */
}
