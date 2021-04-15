#include <iostream>
#include <string_view>

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

        std::cout << "\nFirst Integer core: " << i1.getInt() << std::endl;
        std::cout << "Second Integer core: " << i2.getInt() << std::endl;
        std::cout << "Third Integer core: " << i3.getInt() << std::endl;

        /* This time I need to do this because compare() receives an Integer object
         * by value, and that makes a copy one for that method. */
        std::string_view answers[] {
                i1.traduce(i1.compare(i2)),
                i1.traduce(i1.compare(i3)),
                i2.traduce(i2.compare(i3))
        };

        std::cout << "\ni1 is " << answers[0] << " than i2.\n";
        std::cout << "i1 is " << answers[1] << " than i3.\n";
        std::cout << "i2 is " << answers[2] << " than i3.\n";
}
