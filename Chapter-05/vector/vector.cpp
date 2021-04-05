#include <iostream>
#include <vector>

static void check_for(std::vector<unsigned int> v);

int
main(void)
{
        std::vector<unsigned int> values(20, 99U);
        check_for(values);
        values.clear();
        check_for(values);
}

static void
check_for(std::vector<unsigned int> v)
{
        std::cout << "The vector is ";
        if (v.empty()) {
                std::cout << "empty.";
        } else {
                std::cout << "filled.";
        }
        std::cout << std::endl;
}
