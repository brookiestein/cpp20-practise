/* Exercise 14-2. Change the access specifier for the who() function in the Animal class to */
/* protected , but leave the rest of the class as before. Now modify the derived classes so that */
/* the original version of main() still works without alteration. */

#include <iostream>

#include "lion.h"
#include "aardvark.h"

int
main()
{
        Lion lion { "Leo", 400 };
        Aardvark advk { "Algernon", 50 };

        lion.who();
        advk.who();
}
