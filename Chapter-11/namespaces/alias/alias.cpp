#include <iostream>

namespace very_long_namespace_name
{
        void greet(void)
        {
                std::cout << "Hello world!" << std::endl;
        }
}

int
main(void)
{
        namespace inShort = very_long_namespace_name;
        /* very_long_namespace_name::greet(); */
        inShort::greet();
}
