#include <iostream>

int
main(void)
{
        unsigned int values[] { 1, 2, 3, 4, 5 };

        for (auto& v : values) v++;
        for (const auto& v : values) std::cout << v << ' ';
        std::cout << std::endl;
}
