/* Practising Polymorphism.
 * Accessing derived member function through a base class pointer. */

#include <iostream>

#include "box.h"
#include "carton.h"
#include "though_pack.h"

int
main()
{
        Box box { 20.0, 30.0, 40.0 };
        Carton carton { 20.0, 30.0, 40.0, "Cardboard" };
        ThoughPack though_pack { 20.0, 30.0, 40.0 };

        box.showVolume();
        carton.showVolume();
        though_pack.showVolume();

        Box* base { &box };
        std::cout << "\nBox volume through a base pointer is: " << base->volume() << std::endl;
        base->showVolume();

        base = &carton;
        std::cout << "Carton volume through a base pointer is: " << base->volume() << std::endl;
        base->showVolume();

        base = &though_pack;
        std::cout << "Though Pack volume through a base pointer is: " << base->volume() << std::endl;
        base->showVolume();
}
