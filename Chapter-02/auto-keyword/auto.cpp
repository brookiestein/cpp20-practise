#include <iostream>
#include <typeinfo>
#include <cmath>

int
main(void)
{
        auto i {M_PI};
        std::cout << "The i variable is type " << typeid(i).name() << std::endl;
        return 0;
}
