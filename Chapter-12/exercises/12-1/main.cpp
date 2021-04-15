#include <iostream>

#include "integer.h"

int
main()
{
        Integer i1 {};
        const Integer i2 {};

        i1.setInt(42);
        /* The following won't compile because the setInt() member function
         * is not const to allow a const object modify its member variables.
         * And it can't be const because it, by definition, modifies the object's
         * member variables. */
        /* i2.setInt(50); */

        /* Make a third Integer object from the first one: Copying the object. */
        Integer i3 {i1};

        std::cout << "First Integer core: " << i1.getInt() << std::endl;
        std::cout << "Second Integer core: " << i2.getInt() << std::endl;
        std::cout << "Third Integer core: " << i3.getInt() << std::endl;
}
