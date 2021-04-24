/* Exercise 13-5. Create the necessary operators that allow Box objects to be used in if */
/* statements such as these: */
/* if (my_box) ... */
/* if (!my_other_box) ... */
/* A Box is equivalent to true if it has a nonzero volume; if its volume is zero, a Box */
/* should evaluate to false . Create a small test program that shows your operators work */
/* as requested. */

#include <iostream>
#include <vector>

#include "box.h"

int
main()
{
        Box myBox {3.0, 2.0, 1.0};
        /* A Box that has at least one measure that's zero, indeed, its volume will be zero. */
        Box box {1.0, 2.0, 0.0};

        if (myBox)
                std::cout << "My Box's volume is " << myBox.getVolume() << '.' << std::endl;
        /* I could use an else statement, but using it in this way, shows that
         * even though the negation (!) operator hadn't been defined, this works. */
        if (!box)
                std::cout << "Box's volume is zero (" << box.getVolume() << ")." << std::endl;
}
