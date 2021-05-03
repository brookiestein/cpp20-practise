/* Testing pure virtual functions. */
#include <iostream>

#include "box.h"
#include "carton.h"
#include "though_pack.h"

int
main()
{
        /* This won't compile! Give it a try! */
        /* Box box {20.0, 30.0, 40.0}; */

        Carton carton { 20.0, 30.0, 40.0, "Cardboard" };
        ThoughPack hardcase { 20.0, 30.0, 40.0 };

        /* To separate constructors' output and showVolume() */
        std::cout << std::endl;
        /* A pointer to the base class does can be used, so
         * we can have polymorphic behaviour. */
        Box* base { &carton };
        base->showVolume();

        base = &hardcase;
        base->showVolume();

        /* To separate showVolume()'s output and destructors ones. */
        std::cout << std::endl;
}
