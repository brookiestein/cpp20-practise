/* When catching related exceptions, it is important to catch all of them
 * in an order of: The most derived class first, and the most based class last. */

/* Rethrowing exceptions to an outer try block. */

#include <iostream>
#include <typeinfo>

#include "Troubles.h"

int
main()
{
        for (int i {}; i < 7; ++i) {
                try {
                        try {
                                if (i == 3)
                                        throw Trouble {};
                                if (i == 5)
                                        throw MoreTrouble {};
                                if (i == 6)
                                        throw BigTrouble {};
                        } catch (const Trouble& ex) {
                                if (typeid(ex) == typeid(Trouble))
                                        std::cout << "Trouble exception caught: "
                                                << ex.what() << std::endl;
                                else
                                        throw;
                                /* If you try to rethrow an exception by doing this:
                                 * throw exception; you're not rethrowing it, but you're
                                 * throwing a *new* exception, and if you received it as
                                 * a reference to the base class, probably object slicing
                                 * will occur. */
                        }
                } catch (const Trouble& ex) {
                        std::cout << typeid(ex).name() << " exception caught: "
                                << ex.what() << std::endl;
                }

                std::cout << "After the catch statements, i = " << i << std::endl;
        }
}
