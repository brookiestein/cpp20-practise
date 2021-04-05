#include <iostream>

int value0 {10};
int value1 {15};
int value2; /* This will use the default zero-initialisation. */

int
main(void)
{
        int value0 {20}; /* This will mask the global value0's value. */
        int value3 {42};

        std::cout << "Local value: value0 = " << value0 << std::endl;
        std::cout << "Local value: value3 = " << value3 << std::endl;

        std::cout << "Global value: value0 = " << ::value0 << std::endl;
        std::cout << "Global value: value2 = " << value2 << std::endl;

        /* I've just learnt this. This will open a new block! */
        {
                int value3 {70}; /* This will mask main()'s value3. */
                std::cout << "Local value: value3 = " << value3 << std::endl;
                /* Increasing the global variable's value. */
                ++::value0;
                int value4 {};
        }

        std::cout << "Global value after increased: value0 = " << ::value0 << std::endl;
        /* std::cout << "Value4 = " << value4 << std::endl; /1* This will produce a compiler error, because value4 does not exist in this scope. *1/ */
}
