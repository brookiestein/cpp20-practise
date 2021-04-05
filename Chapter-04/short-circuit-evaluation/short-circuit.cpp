#include <iostream>

int
main(void)
{
        int x {-634};
        if (x < 0 && (x * x + 632 * x == 1268)) {
                std::cout << "Congrats " << x << " is the correct solution!\n";
        }
}
