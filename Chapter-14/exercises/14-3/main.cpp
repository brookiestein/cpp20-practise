/* Exercise 14-3. In the solution to the previous exercise, change the access specifier for the */
/* who() member of the base class back to public and implement the who() function as a */
/* member of each derived class so that the output message also identifies the name of the */
/* class. Change main() to call the base class and derived class versions of who() for each of the */
/* derived class objects. */

#include <iostream>

#include "lion.h"
#include "aardvark.h"

int
main()
{
        Lion lion { "Leo", 400 };
        Aardvark advk { "Algernon", 50 };

        lion.who();
        std::cout << std::endl;
        advk.who();
        std::cout << std::endl;
        lion.Animal::who();
        std::cout << std::endl;
        advk.Animal::who();
}
