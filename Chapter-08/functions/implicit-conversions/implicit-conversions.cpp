#include <iostream>

void double_it(double& it) { it *= 2; }
void print_it(const double& it) { std::cout << it << std::endl; }

int
main(void)
{
        int i {1};
        double d {1};

        std::cout << "Working with d." << std::endl;
        double_it(d);
        print_it(d);
        std::cout << std::endl;

        std::cout << "Working with i." << std::endl;
        /* double_it(i); */
        print_it(i);
}
