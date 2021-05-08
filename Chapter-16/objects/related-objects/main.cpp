/* When catching related exceptions, it is important to catch all of them
 * in an order of: The most derived class first, and the most based class last. */

#include <iostream>
#include <typeinfo>

#include "Troubles.h"

int
main()
{
        for (int i {}; i < 7; ++i) {
                try {
                        if (i == 3)
                                throw Trouble {};
                        if (i == 5)
                                throw MoreTrouble {};
                        if (i == 6)
                                throw BigTrouble {};
                        /* Dynamic type of objects is retained, because the parameter
                         * is a reference. If it were received by value, then it base
                         * class subobject only were retained instead.
                         * That's the most valuable reason why we should receive exception
                         * parameters as references. */
                } catch (const Trouble& e) {
                        std::cout << typeid(e).name() << " object caught: "
                                << e.what() << '\n' << std::endl;
                }

                std::cout << "After the catch statements, i = " << i << std::endl;
        }
}
