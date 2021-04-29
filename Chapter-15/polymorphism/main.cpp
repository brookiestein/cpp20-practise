/* Practising Polymorphism.
 * Accessing derived member function through a base class pointer. */

/* Note how volume() can be accessed through a pointer to the base class,
 * and not directly through an object of the class. */

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

        /* In this case, this won't work because volume() is a private member of the Carton class. */
        /* This couldn't work because volume() had been private, but to practise default argument values
         * in virtual functions this function has come back to be public. */
        std::cout << "Carton volume through a Carton object is: " << carton.volume() << std::endl;

        base = &though_pack;
        std::cout << "Though Pack volume through a base pointer is: " << base->volume() << std::endl;
        base->showVolume();
}
