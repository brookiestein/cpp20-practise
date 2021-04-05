#include <iostream>

int
main(void)
{
        int test {3};
        switch (test)
        {
        case 1:
                std::cout << 1 << std::endl;
                break;
        case 2:
                std::cout << 2 << std::endl;
                break;
        case 3:
        {
                int k {5};
                std::cout << test + k << std::endl;
        }
        default:
                int m {10};
                std::cout << test + m + k << std::endl;
        }
}
