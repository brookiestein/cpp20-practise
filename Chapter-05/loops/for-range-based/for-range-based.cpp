#include <iostream>

int
main(void)
{
        const unsigned int values[] {2, 3, 5, 7, 11, 13, 19, 23, 29};
        unsigned int total {};

        for (auto v : values) {
                std::cout << v << " ";
                total += v;
        }

        std::cout << "= " << total << std::endl;
}
