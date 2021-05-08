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
                        } catch (const BigTrouble& big_trouble) {
                                std::cout << "Oh, a big trouble has occur! Let's "
                                        << "treat it here and now: "
                                        << big_trouble.what() << std::endl;
                        } catch (...) {
                                std::cout << "Something else has occur. Let's rethrow it!\n";
                                throw;
                        }
                } catch (const Trouble& ex) {
                        std::cout << typeid(ex).name() << " exception caught: "
                                << ex.what() << std::endl;
                }

                std::cout << "After the catch statements, i = " << i << std::endl;
        }
}
