/* Using an alias of an rvalue reference. */

#include <iostream>

int
main()
{
        int count {5};
        int&& rtemp {count + 3}; /* rvalue reference. */
        std::cout << rtemp << std::endl;
        /* int &rcount {count + 3}; /1* This is not possible in *normal* references. *1/ */
}
